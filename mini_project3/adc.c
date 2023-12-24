/*
 * adc.c
 *
 *  Created on: Oct 6, 2023
 *      Author: Donia
 */
#include "adc.h"
#include<avr/io.h>
#include"common_macros.h"
#include <avr/interrupt.h>

#if (ADC_POLL==0)
volatile uint16 adc_result=0;
ISR(ADC_vect){
	adc_result=ADC;
}
#endif
void ADC_init(const ADC_ConfigType *Config_Ptr){
	//Config ref_volt
	ADMUX=(ADMUX&0x3F)|((Config_Ptr->ref_volt)<<6);
	ADCSRA|=(1<<ADEN);
#if (ADC_POLL==0)
	ADCSRA||(1<<ADIE);
#endif
	ADCSRA=(ADCSRA&0xF8)|(Config_Ptr->prescaler);
}
uint16 ADC_readChannel(uint8 ch_num){

	ADMUX = (ADMUX&0xE0)|(ch_num&0x07);//make sure that frist 5 bits is zero (MUX(0->4))
	SET_BIT(ADCSRA,ADSC);
#if(ADC_POLL==1)
while(BIT_IS_CLEAR(ADCSRA,ADIF));
SET_BIT(ADCSRA,ADIF);
return ADC;
#endif

}
