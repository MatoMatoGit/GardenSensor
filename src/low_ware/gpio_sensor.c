/*
 * gpio_sensor.c
 *
 * Created: 16-03-2019 22:42:28
 *  Author: dorspi
 */

#include "gpio_sensor.h"

#include <avr/io.h>

#define DDR_SENSOR	DDRB
#define PORT_SENSOR	PORTB

#define PIN_SENSOR_PWR		PINB3
#define PIN_SENSOR_MOISTURE	PINB1
#define PIN_SENSOR_LIGHT	PINB2
#define PIN_SENSOR_TEMPERATURE	PINB4

void GpioSensorPowerInit(void)
{
	DDR_SENSOR |= (1 << PIN_SENSOR_PWR);
}

void GpioSensorMoistureInit(void)
{
	DDR_SENSOR &= ~(1 << PIN_SENSOR_MOISTURE);
}

void GpioSensorTemperatureInit(void)
{
	DDR_SENSOR &= ~(1 << PIN_SENSOR_TEMPERATURE);
}

void GpioSensorLightInit(void)
{
	DDR_SENSOR &= ~(1 << PIN_SENSOR_LIGHT);
}

void GpioSensorPowerStateSet(uint8_t state)
{
	if(state) {
		PORT_SENSOR |= (1 << PIN_SENSOR_PWR);
	} else {
		PORT_SENSOR &= ~(1 << PIN_SENSOR_PWR);
	}
}

