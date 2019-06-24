
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <avr/io.h>
#include <util/delay.h>

//#include "SoftwareSerial.h"
#include "sensor.h"
#include "garden_sensor_slave.h"

#define SOFTSERIAL_TX_DDR	DDRB
#define SOFTSERIAL_TX_PORT	PORTB
#define SOFTSERIAL_TX_PIN	PINB1

/* avrdude.exe -p t85 -B 25 -c U flash:w:"C:\Users\dorspi\Documents\Atmel Studio\7.0\mvsensor_fw\Debug\mvsensor_fw.hex":i */

static uint16_t GardenSensorRead(SensorType_e type);
static SensorStatus_e GardenSensorStatus(void);

static SensorStatus_e SensorStatus = SENSOR_STATUS_OK;

int main(void)
{
	/* Initialize drivers. */
	SensorInit();
	GardenSensorInit(GardenSensorRead, GardenSensorStatus);

	//softSerialInit(&DDRB, &PORTB, NULL, SOFTWARE_SERIAL_RX_DISABLED, SOFTSERIAL_TX_PIN);
	//softSerialBegin(2400);

    while (1)
    {

    }
}

static uint16_t GardenSensorRead(SensorType_e type)
{
	uint16_t sensor_value = 0;

	switch(type) {
	case SENSOR_TYPE_MOISTURE:
		sensor_value = SensorMoistureRead();
		break;
	case SENSOR_TYPE_TEMP:
		sensor_value = SensorTemperatureRead();
		break;
	case SENSOR_TYPE_LIGHT:
		sensor_value = SensorLightRead();
		break;
    default:
        break;
	}

	return sensor_value;
}

static SensorStatus_e GardenSensorStatus(void)
{
	return SensorStatus;
}

