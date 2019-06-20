/*
 * sensor.c
 *
 * Created: 16-03-2019 22:47:46
 *  Author: dorspi
 */ 

#include "sensor.h"

#include "filter.h"
#include "SoftwareSerial.h"

#include "adc.h"
#include "gpio_sensor.h"

#include <util/delay.h>

#define ADC_CH_MOISTURE_SENSOR 2
#define ADC_CH_TEMPERATURE_SENSOR 0
#define ADC_CH_LIGHT_SENSOR 1

static uint16_t SensorRead(uint8_t adc_ch);

static FilterDataType_t sensor_filter_buf[SENSOR_FILTER_DEPTH];

static Filter_t sensor_filter = {
	.n = SENSOR_FILTER_DEPTH,
	.buffer = sensor_filter_buf
};

void SensorInit(void)
{
	GpioSensorPowerInit();
	GpioSensorMoistureInit();
	GpioSensorTemperatureInit();
	GpioSensorLightInit();
	AdcInit();
}

void SensorDeinit(void)
{
	AdcDeinit();
}

uint16_t SensorMoistureRead(void)
{
	return SensorRead(ADC_CH_MOISTURE_SENSOR);
}

uint16_t SensorTemperatureRead(void)
{
	return SensorRead(ADC_CH_TEMPERATURE_SENSOR);
}

uint16_t SensorLightRead(void)
{
	return SensorRead(ADC_CH_LIGHT_SENSOR);
}

static uint16_t SensorRead(uint8_t adc_ch)
{
	uint16_t value = 0;

	/* Reset the filter. */
	FilterInit(&sensor_filter);

	/* Enable the sensor power and allow the power
	 * to stabilize. */
	GpioSensorPowerStateSet(1);
	_delay_ms(25);

	/* Read N samples to fill the filter. */
	for(uint8_t i = 0; i < n; i++) {
		FilterIn(&sensor_filter, AdcChannelRead(adc_ch));
	}

	/* Disable the sensor power. */
	GpioSensorPowerStateSet(0);

	/* Acquire the filter output. */
	FilterOut(&sensor_filter, &value);

	return value;
}
