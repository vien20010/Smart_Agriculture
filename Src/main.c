#include "stm32f4xx.h"                  // Device header
#include "I2C.h"
#include "BH1750.h"
#include "Systick.h"

uint16_t lux;
int main()
{    
	Systick_Configuration();
    I2C_Config();
    while (1)
    {
        lux=GetLightIntensity();
    }
}