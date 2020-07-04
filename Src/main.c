#include "stm32f4xx.h"                  // Device header
#include "I2C.h"
#include "BH1750.h"
#include "Systick.h"
#include "DS18B20.h"
#include "Timerx.h"
uint16_t lux;
float Water_Temperature;
int main()
{    
	Systick_Configuration();
    //I2C_Config();
    TIM6_Config();
    while (1)
    {
        //lux=GetLightIntensity();
        Water_Temperature=GetWaterTemp();
    }
}