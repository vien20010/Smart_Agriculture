/* 
* July 03, 2020
* LV_Embedded
 */
 
#ifndef MAX44009_H
#define MAX44009_H

#include "../Src/stm32f4xx.h"
#include "I2C.h"
#include "Systick.h"
#include <math.h>

#define MAX44009_ADDRESS 			0x94

void MAX44009_Config(void);
float MAX44009_GetLightIntensity(void);

#endif