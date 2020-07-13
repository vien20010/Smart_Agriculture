/* 
* July 04, 2020
* LV_Embedded
 */

#include "GPIO.h"

/**
 * 
 * @param GPIOx - GPIO Port want to set
 * @param GPIO_Pin - GPIO Pin want to set
 * @param Set_Pin_Output - Set GPIO_Pin of GPIOx PORT mode OUTPUT
 **/

void Set_Pin_Output(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;
    GPIO_Init(GPIOx,&GPIO_InitStructure);
}

/**
 * 
 * @param GPIOx - GPIO Port want to set
 * @param GPIO_Pin - GPIO Pin want to set
 * @param Set_Pin_Input - Set GPIO_Pin of GPIOx PORT mode OUTPUT
 **/

void Set_Pin_Input(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin;
    GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
    GPIO_Init(GPIOx,&GPIO_InitStructure);
}
