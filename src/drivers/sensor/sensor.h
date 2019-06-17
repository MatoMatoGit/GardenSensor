/*
 * sensor.h
 *
 * Created: 16-03-2019 22:38:51
 *  Author: dorspi
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_

#include <stdint.h>

#define SENSOR_FILTER_DEPTH		25

void SensorInit(void);

uint16_t SensorMoistureRead(void);
uint16_t SensorTemperatureRead(void);
uint16_t SensorLightRead(void);

#endif /* SENSOR_H_ */
