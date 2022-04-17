#ifndef __KEYPASSWD_H__
#define __KEYPASSWD_H__
#include "stm32f10x.h"


#define ROW_1_LOW() GPIO_ResetBits(GPIOA,GPIO_Pin_15)
#define ROW_2_LOW() GPIO_ResetBits(GPIOB,GPIO_Pin_3)
#define ROW_3_LOW() GPIO_ResetBits(GPIOB,GPIO_Pin_4)
#define ROW_4_LOW() GPIO_ResetBits(GPIOB,GPIO_Pin_5)

#define COLUMN_1_READ() GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)
#define COLUMN_2_READ() GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)
#define COLUMN_3_READ() GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)
#define COLUMN_4_READ() GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)

#define KEY_NULL 99

void Keypasswd_Init(void);
void ROW_ALL_HIGH(void);
uint8_t Key_Scan(void);

#endif
