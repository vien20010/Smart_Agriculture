/* 
June 13,2020
LV_Embedded
 */
#ifndef TIMERX_H
#define TIMERX_H

#include "../Src/stm32f4xx.h"

void TIM6_Config();
void Interrupt_Config();
void Timer6Delay_us(uint32_t us);


#endif