/* 
* July 04, 2020
* LV_Embedded
 */

#include "DS18B20.h"
/**
 * 
 * @param DS18B20_Star - Initialization Timing for DS18B20
 *  
 **/
uint8_t DS18B20_Star(void)
{
    uint8_t Response = 0;
    RCC_AHB1PeriphClockCmd(DS18B20_CLK, ENABLE); 
    Set_Pin_OutPut(DS18B20_PORT, DS18B20_PIN); //Set the pin as output
    GPIO_WriteBit(DS18B20_PORT, DS18B20_PIN, 0); //pull the pin low
    Timer6Delay_us(480); //delay according to datasheet

    Set_Pin_Input(DS18B20_PORT, DS18B20_PIN); //Set the pin as input
    Timer6Delay_us(80); //delay according to datasheet
    if (!(GPIO_ReadInputDataBit(DS18B20_PORT, DS18B20_PIN)))
        Response = 1; //if the pin is low, the presence pulse is detected
    else
        Response = -1; 
    Timer6Delay_us(400); //480 us delay totally

    return Response;
}

/** 
 *  
 *  @param data - the data you want to write on sensor 
 *  @param DS18B20_Write - function wire data to sensor
 * 
 **/
/* 
There are two type of write time slot: "Write 1" and "Write 0"

To generate a Write 0 time slot, after pulling the 1-Wire bus low, 
the master must continue to hold the bus low 
for the duration of the time slot (at least 60µs) 

To generate a Write 1, after pulling the 1-Wire bus low, 
the master must release the 1-Wire bus within 15µs. When the bus is released, 
the 5kΩ pullup resistor will pull the bus high.
*/


void DS18B20_Write(uint8_t data)
{
    Set_Pin_OutPut(DS18B20_PORT,DS18B20_PIN);
    for (int i=0;i<0;i++)
    {
        if ((data&(1<<i))!=0)
        {
            /* Write 1 time slot */
            Set_Pin_OutPut(DS18B20_PORT, DS18B20_PIN);
            GPIO_WriteBit(DS18B20_PORT, DS18B20_PIN, 0);
            Timer6Delay_us(1);

            Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);
            Timer6Delay_us(60);
        }
        else
        {
            /* Write 0 time slot */
            Set_Pin_OutPut(DS18B20_PORT, DS18B20_PIN);
            GPIO_WriteBit(DS18B20_PORT, DS18B20_PIN,0);
            Timer6Delay_us(60);

            Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);
        }
    }
}

/* 
A read time slot is initiated by the master device 
pulling the 1-Wire bus low for a minimum of 1µs and then releasing the bus 

*/

uint8_t DS18B20_Read(void)
{
    uint8_t value=0;
    Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);
    for (int i=0;i<8;i++)
    {
        Set_Pin_OutPut(DS18B20_PORT, DS18B20_PIN);
        GPIO_WriteBit(DS18B20_PORT, DS18B20_PIN,0);
        Timer6Delay_us(2);

        Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);
        if (GPIO_ReadInputDataBit(DS18B20_PORT, DS18B20_PIN))
        {
            value|=1<<i;
        }
        Timer6Delay_us(60);
    }
    return value;
}

float GetWaterTemp(void)
{
    uint8_t temp_water[2];
    uint8_t Presence;
    uint32_t temp1;
    float temp2;
    Presence=DS18B20_Star();
    SystickDelay_ms(1);
    DS18B20_Write(0xCC);
    DS18B20_Write(0x44);
    SystickDelay_ms(800);
        
    Presence=DS18B20_Star();
    SystickDelay_ms(1);
    DS18B20_Write(0xCC);
    DS18B20_Write(0xBE);
    
    temp_water[0]=DS18B20_Read();
    temp_water[1]=DS18B20_Read();

    temp1=temp_water[0];
    temp1=(temp1<<8)|temp_water[1];
    temp2=(float)temp1/16.0;
    return temp2;
}