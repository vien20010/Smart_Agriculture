#include "stm32f4xx.h"                  // Device header
#include "I2C.h"
#include "Systick.h"

uint8_t count=0;
float temp,humd;
uint8_t buffer[4];
int main()
{    
		Systick_Configuration();
    I2C_Config();
    while (1)
    {
        I2C_Read(I2Cxx,SLAVE_ADDRESS,0x00,buffer,4);
				SystickDelay_ms(1000);
        humd=(float)buffer[0]+(float)buffer[1]/10.0;
        temp=(float)buffer[2]+(float)buffer[3]/10.0;
				count++;
    }
}