/* 
June 13,2020
LV_Embedded
 */

#include "Timerx.h"

void TIM6_Config()
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period= 1;
    TIM_TimeBaseStructure.TIM_Prescaler=83;
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM6,&TIM_TimeBaseStructure);
    TIM_Cmd(TIM6,ENABLE);
}
/* Interrupt Configuration */
void Interrupt_Config()
{
    NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
void Timer6Delay_us(uint32_t us)
{
    TIM_SetCounter(TIM6,0);
    while(TIM_GetCouter(TIM6)<us);
}