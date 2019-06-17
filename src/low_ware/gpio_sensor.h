/*
 * gpio_sensor.h
 *
 * Created: 16-03-2019 22:41:33
 *  Author: dorspi
 */ 


#ifndef GPIO_SENSOR_H_
#define GPIO_SENSOR_H_

#include <stdint.h>

void GpioSensorPowerInit(void)
void GpioSensorMoistureInit(void);
void GpioSensorTemperatureInit(void);
void GpioSensorLightInit(void);

void GpioSensorPowerStateSet(uint8_t state);

#endif /* GPIO_SENSOR_H_ */
