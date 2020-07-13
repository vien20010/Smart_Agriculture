/* 
* July 03, 2020
* LV_Embedded
 */

#include "../Src/stm32f4xx.h"
#include "I2C.h"
#include "BH1750.h"
#include "Systick.h"

uint8_t buffer_Light[2];
uint16_t GetLightIntensity(void)
{
    
    uint16_t Intensity_Value=0;
    I2C_Read(I2Cxx,BH1750_ADDRESS,Continuous_H_resolution_Mode,buffer_Light,2);
    SystickDelay_ms(1000);
    Intensity_Value=buffer_Light[0];
    Intensity_Value=(Intensity_Value<<8)|buffer_Light[1];
    Intensity_Value/=1.2;
    return Intensity_Value;
}
