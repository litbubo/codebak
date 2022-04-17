#include "stm32f10x.h"                

uint8_t rev[17];
char *ack_open = "#open the door!*";
char *ack_close = "#close the door*";
char *ack_wifi = "#WiFi Connected*";

void UART2_IO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void UART2_Init(uint32_t bound)
{

    NVIC_InitTypeDef NVIC_InitStruct;
    USART_InitTypeDef USART_InitStruct;

    UART2_IO_Init();

    USART_DeInit(USART2);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2| RCC_APB2Periph_AFIO, ENABLE);

    USART_InitStruct.USART_BaudRate = bound;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART2, &USART_InitStruct);

    NVIC_InitStruct.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;
    NVIC_Init(&NVIC_InitStruct);

    USART_ITConfig(USART2,USART_IT_RXNE, ENABLE);

    USART_Cmd(USART2, ENABLE);
}
