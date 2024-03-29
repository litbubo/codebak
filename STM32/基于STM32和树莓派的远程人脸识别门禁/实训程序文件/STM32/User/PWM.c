#include "stm32f10x.h"                  // Device header

void TIM3_PWM_Init(uint16_t arr, uint16_t psc)
{
    /*
        GPIO_InitTypeDef GPIO_InitStructure;
        TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
        TIM_OCInitTypeDef TIM_OCInitStruct;

        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);

        GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; //TIM_CH2
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOB, &GPIO_InitStructure);

        TIM_TimeBaseInitStruct.TIM_Period = arr;
        TIM_TimeBaseInitStruct.TIM_Prescaler = psc;
        TIM_TimeBaseInitStruct.TIM_ClockDivision = 0;
        TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
        TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);

        TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM2;
        TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
        TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
        TIM_OC2Init(TIM3, &TIM_OCInitStruct);

        TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
        TIM_Cmd(TIM3, ENABLE);
    */

    GPIO_InitTypeDef GPIO_InitStruct;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_OCInitTypeDef TIM_OCInitStruct;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    //GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7; //TIM_CH2
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;  
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    TIM_TimeBaseInitStruct.TIM_Period = arr;
    TIM_TimeBaseInitStruct.TIM_Prescaler = psc;
    TIM_TimeBaseInitStruct.TIM_ClockDivision = 0;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC2Init(TIM3, &TIM_OCInitStruct);

    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_Cmd(TIM3, ENABLE);
}
