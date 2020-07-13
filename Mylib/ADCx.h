/** 
 * 
 * July 10, 2020
 * LV_Embedded
 * nguyenlamvien0110@gmail.com 
 * https://github.com/vien20010
 * 
 **/

#ifndef _ADCx_H_
#define _ADCx_H_

#include "../Src/stm32f4xx.h"

#define ADCxx                    ADC3
#define ADC_CHANNEL              ADC_Channel_1
#define ADCx_CLK                 RCC_APB2Periph_ADC3
#define ADCx_CHANNEL_GPIO_CLK    RCC_AHB1Periph_GPIOA
#define GPIO_PIN                 GPIO_Pin_1
#define GPIO_PORT                GPIOA
#define DMA_CHANNELx             DMA_Channel_2
#define DMA_STREAMx              DMA2_Stream0
#define ADCx_DR_ADDRESS          ((uint32_t)0x4001224C)
#define DMA_CLK                  RCC_AHB1Periph_DMA2
void ADC_Config(void);
void DMA_Config(void);

#endif
