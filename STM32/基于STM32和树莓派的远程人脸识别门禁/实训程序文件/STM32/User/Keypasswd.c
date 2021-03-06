#include "Keypasswd.h"
#include "delay.h"

void Keypasswd_Init()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA,GPIO_Pin_15);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void ROW_ALL_HIGH()
{
	GPIO_SetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5);
	GPIO_SetBits(GPIOA,GPIO_Pin_15);
}

uint8_t Key_Scan()
{
    uint8_t key_num = KEY_NULL;
	
    ROW_ALL_HIGH();
    ROW_1_LOW();
    if(COLUMN_1_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_1_READ() == 0) ;
        delay_ms(20);
        key_num = 1;
    }
    if(COLUMN_2_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_2_READ() == 0) ;
        delay_ms(20);
        key_num = 2;
    }
    if(COLUMN_3_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_3_READ() == 0) ;
        delay_ms(20);
        key_num = 3;
    }
    if(COLUMN_4_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_4_READ() == 0) ;
        delay_ms(20);
        key_num = 10;
    }

    ROW_ALL_HIGH();
    ROW_2_LOW();
    if(COLUMN_1_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_1_READ() == 0) ;
        delay_ms(20);
        key_num = 4;
    }
    if(COLUMN_2_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_2_READ() == 0) ;
        delay_ms(20);
        key_num = 5;
    }
    if(COLUMN_3_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_3_READ() == 0) ;
        delay_ms(20);
        key_num = 6;
    }
    if(COLUMN_4_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_4_READ() == 0) ;
        delay_ms(20);
        key_num = 11;
    }

    ROW_ALL_HIGH();
    ROW_3_LOW();
    if(COLUMN_1_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_1_READ() == 0) ;
        delay_ms(20);
        key_num = 7;
    }
    if(COLUMN_2_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_2_READ() == 0) ;
        delay_ms(20);
        key_num = 8;
    }
    if(COLUMN_3_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_3_READ() == 0) ;
        delay_ms(20);
        key_num = 9;
    }
    if(COLUMN_4_READ() == 0) {
        delay_ms(20);
        while(COLUMN_4_READ() == 0) ;
        delay_ms(20);
        key_num = 12;
    }

    ROW_ALL_HIGH();
    ROW_4_LOW();
    if(COLUMN_1_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_1_READ() == 0) ;
        delay_ms(20);
        key_num = 14;
    }
    if(COLUMN_2_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_2_READ() == 0) ;
        delay_ms(20);
        key_num = 0;
    }
    if(COLUMN_3_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_3_READ() == 0) ;
        delay_ms(20);
        key_num = 15;
    }
    if(COLUMN_4_READ() == 0)
    {
        delay_ms(20);
        while(COLUMN_4_READ() == 0) ;
        delay_ms(20);
        key_num = 13;
    }

    return key_num;
}
