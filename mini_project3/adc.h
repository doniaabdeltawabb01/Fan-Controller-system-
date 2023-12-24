#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
//enum
typedef enum {
	AREF,AVCC,RESERVED,INTERNAL
}ADC_ReferenceVolatge;

typedef enum {
 DIVISION_FACTOR1, DIVISION_FACTOR2, DIVISION_FACTOR4, DIVISION_FACTOR8, DIVISION_FACTOR16, DIVISION_FACTOR32, DIVISION_FACTOR64, DIVISION_FACTOR128
}ADC_Prescaler;


//STRUCT
typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;
//defines
#define ADC_POLL       1
#if (ADC_POLL==0)
extern volatile uint16 adc_result;
#endif
#define ADC_MAX_VALUE 1023
#define ADC_V_REF    2.56


//protypes

void ADC_init(const ADC_ConfigType *Config_Ptr);
uint16 ADC_readChannel(uint8 ch_num);

#endif
