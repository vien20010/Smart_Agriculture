/** 
 * 
 * July 10, 2020
 * LV_Embedded
 * nguyenlamvien0110@gmail.com 
 * https://github.com/vien20010
 * 
 **/

#include "ADCx.h"

/**
  * @brief  ADC3 channel07 with DMA configuration
  * @note   This function Configure the ADC peripheral  
            1) Enable peripheral clocks
            2) DMA2_Stream0 channel2 configuration
            3) Configure ADC Channel7 pin as analog input
            4) Configure ADC3 Channel7 
  * @param  None
  * @retval None
  */

void ADC_Config(void)
{
    ADC_InitTypeDef             ADC_InitStructure;
    ADC_CommonInitTypeDef       ADC_CommonInitStructure;
    GPIO_InitTypeDef            GPIO_InitStructure;

    /* Enable ADCx, GPIO clocks */

    RCC_AHB1PeriphClockCmd(ADCx_CHANNEL_GPIO_CLK, ENABLE);  
    RCC_APB2PeriphClockCmd(ADCx_CLK, ENABLE);

    /* Configure ADC3 Channel7 pin as analog input ******************************/
    GPIO_InitStructure.GPIO_Pin = GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
    GPIO_Init(GPIO_PORT, &GPIO_InitStructure);

    /* ADC Common Init **********************************************************/
    ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
    ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
    ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
    ADC_CommonInit(&ADC_CommonInitStructure);

    /* ADC3 Init ****************************************************************/
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfConversion = 1;
    ADC_Init(ADCx, &ADC_InitStructure);

    /* ADC3 regular channel7 configuration **************************************/
    ADC_RegularChannelConfig(ADCx, ADC_CHANNEL, 1, ADC_SampleTime_3Cycles);

    /* Enable ADC3 */
    ADC_Cmd(ADCx, ENABLE);
}
