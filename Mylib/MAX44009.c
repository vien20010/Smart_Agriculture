/* 
* July 03, 2020
* LV_Embedded
 */
 
 #include "MAX44009.h"

uint8_t buffer_MAX;
float MAX44009_GetLightIntensity(void)
{
	float Value=0;
	I2C_Read(I2Cxx,MAX44009_ADDRESS,0x03,&buffer_MAX,1);
	SystickDelay_ms(800);
	Value=pow(2.0,((buffer_MAX>>4)&0x0F))*(buffer_MAX&0x0F)*0.72;
	return Value;
}