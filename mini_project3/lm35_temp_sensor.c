/*
 * lm35_temp_sensor.c
 *
 *  Created on: Oct 6, 2023
 *      Author: Donia
 */
#include"lm35_temp_sensor.h"
#include"adc.h"
#include<util/delay.h>

uint8 LM35_getTemp(void)
{
	uint8 temp_value=0;

	//read the adc (temp channel)
	uint16 adc_result=0;
	adc_result=ADC_readChannel(SENSOR_CHANNEL_ID);
	_delay_ms(5);
	//temp equation
	temp_value=(uint8)(((uint32)adc_result*SENSOR_MAX_TEMP*ADC_V_REF)/(ADC_MAX_VALUE*SENOR_MAX_VOLTAGE));

	return temp_value;

}

