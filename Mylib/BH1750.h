/* 
* July 03, 2020
* LV_Embedded
 */
#ifndef BH1750_H
#define BH1750_H

#include "../Src/stm32f4xx.h"
#include "I2C.h"
/* To use ADDRESS BH1750_ADDRESS_H 0xB8, 
the Pin ADDR in BH1750 must be set 'H' (ADDR >=0.7VCC) */
/* Uncomment the line below if you will use ADDRESS High  */

#define BH1750_ADDRESS_H

#ifdef BH1750_ADDRESS_H
    #define BH1750_ADDRESS        0xB8
#else
    #define BH1750_ADDRESS        0x46
#endif

//all command here taken from Data sheet OPECODE Table page 5
#define Power_Down 0x00

#define Power_On 0x01

#define reset 0x07

#define Continuous_H_resolution_Mode  0x10

#define Continuous_H_resolution_Mode2  0x11

#define Continuous_L_resolution_Mode  0x13

#define OneTime_H_resolution_Mode  0x20

#define OneTime_H_resolution_Mode2  0x21

#define OneTime_L_resolution_Mode  0x23//As well as address value

uint16_t GetLightIntensity(void);

#endif
