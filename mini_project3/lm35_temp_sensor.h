#ifndef LM35_TEMP_SESOR_H_
#define LM35_TEMP_SESOR_H_
//define the file.h
#include "std_types.h"

//defines
#define SENOR_MAX_VOLTAGE  1.5
#define SENSOR_MAX_TEMP    150
#define SENSOR_CHANNEL_ID   2

//function prototypes
uint8 LM35_getTemp(void);

#endif
