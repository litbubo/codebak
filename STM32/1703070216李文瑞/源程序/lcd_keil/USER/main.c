#include "stm32f10x.h"
#include "LQ12864.h"
#include "adc.h"
#include "stdio.h"
#include "delay.h"
#include "DTH11.h"

#define NONE_KEY 0
#define UP_KEY 1
#define DOWN_KEY 2
#define OK_KEY 3
#define ESC_KEY 4

int KEY_Read()
{
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
    {
        return UP_KEY;
    }
    else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
    {
        return DOWN_KEY;
    }
    else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_2) == 0)
    {
        return OK_KEY;
    }
    else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3) == 0)
    {
        return ESC_KEY;
    }
    else
    {
        return NONE_KEY;
    }
}

void KEY_GPIO_Config(void)
{

    GPIO_InitTypeDef key_Struct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    key_Struct.GPIO_Mode = GPIO_Mode_IPU;
    key_Struct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    key_Struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &key_Struct);
}

void FAN_GPIO_Config(void)
{
    GPIO_InitTypeDef fan_Struct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    fan_Struct.GPIO_Mode = GPIO_Mode_Out_PP;
    fan_Struct.GPIO_Pin = GPIO_Pin_1;
    fan_Struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &fan_Struct);
    GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

void Buzzer_GPIO_Config(void)
{
    GPIO_InitTypeDef buz_Struct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    buz_Struct.GPIO_Mode = GPIO_Mode_Out_PP;
    buz_Struct.GPIO_Pin = GPIO_Pin_2;
    buz_Struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &buz_Struct);
    GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

void LED_GPIO_Config(void)
{

    GPIO_InitTypeDef led_Struct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    led_Struct.GPIO_Mode = GPIO_Mode_Out_PP;
    led_Struct.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
    led_Struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &led_Struct);
    GPIO_SetBits(GPIOA, GPIO_Pin_3);
    GPIO_SetBits(GPIOA, GPIO_Pin_4);
}

void FanOn()
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

void FanOff()
{
    GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

void BuzzerOn()
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

void BuzzerOff()
{
    GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

void Led1On()
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_3);
}

void Led1Off()
{
    GPIO_SetBits(GPIOA, GPIO_Pin_3);
}

void Led2On()
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_4);
}

void Led2Off()
{
    GPIO_SetBits(GPIOA, GPIO_Pin_4);
}

void main_delay(int ms)
{
    int i, j;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 1000; j++)
        {
            ;
        }
    }
}

int main(void)
{
    int page = 1;
    int l1 = -1, l2 = -1, f = -1, b = -1;
    int i = 0;
    int j = 0;
    u8 temp;
    u8 hum;
    uint16_t val;
    char buf_temp[30] = {0};
    char buf_hum[30] = {0};
    char buf_light[100] = {0};
    char tip1[100] = {0};
    char tip2[100] = {0};
    //delay_init();
    LCD_Init();
    Adc_Init();
    DHT11_Init();
    FAN_GPIO_Config();
    Buzzer_GPIO_Config();
    LED_GPIO_Config();

    while (1)
    {
        int key1;
        LCD_P6x8Str(8, 0, (unsigned char *)"Auto");
        LCD_P6x8Str(8, 2, (unsigned char *)"Manual");
/*
        LCD_P6x8Str(54, i, (unsigned char *)"<-");
        main_delay(300);
        key1 = KEY_Read();
        if (key1 == UP_KEY)
        {
            if (i == 2)
            {
                i = 0;
            }
            else
            {
                i = 2;
            }
            LCD_CLS();
        }
        else if (key1 == DOWN_KEY)
        {
            if (i == 0)
            {
                i = 2;
            }
            else
            {
                i = 0;
            }
            LCD_CLS();
        }
        else if (key1 == OK_KEY)
        {
            if (i == 0)
                page = 2;
            else
                page = 3;
            LCD_CLS();
        }

        while (page == 2)
        {
            int key2;
            // val = Get_Adc(); 
            DHT11_Read_Data(&temp, &hum);
            sprintf(buf_temp, "temp: %d", temp);
            sprintf(buf_hum, "hum: %d", hum);
            sprintf(buf_light, "light:%d", val);
            LCD_P6x8Str(8, 0, (unsigned char *)buf_temp);
            LCD_P6x8Str(8, 2, (unsigned char *)buf_hum);
            LCD_P6x8Str(8, 4, (unsigned char *)buf_light);
            delay_ms(100);
            key2 = KEY_Read();

            if (temp > 28)
            {
                BuzzerOn();
                FanOn();
                b = 1;
                f = 1;
            }
            else
            {
                BuzzerOff();
                FanOff();
                b = -1;
                f = -1;
            }
            if (val < 2000)
            {
                Led1On();
                Led2On();
                l1 = 1;
                l2 = 1;
            }
            else
            {
                Led1Off();
                Led2Off();
                l1 = -1;
                l2 = -1;
            }
            if (key2 == ESC_KEY)
            {
                page = 1;
                LCD_CLS();
                break;
            }
        }

        while (page == 3)
        {
            int key3;
            sprintf(tip1, "L1:%d L2:%d", l1, l2);
            sprintf(tip2, "F:%d Beep:%d", f, b);
            LCD_P6x8Str(0, 0, (unsigned char *)"LED1");
            LCD_P6x8Str(0, 1, (unsigned char *)"LED2");
            LCD_P6x8Str(0, 2, (unsigned char *)"FAN");
            LCD_P6x8Str(0, 3, (unsigned char *)"BEEP");
            LCD_P6x8Str(2, 4, (unsigned char *)tip1);
            LCD_P6x8Str(2, 5, (unsigned char *)tip2);
            LCD_P6x8Str(30, j, (unsigned char *)"<-");
            main_delay(300);
            key3 = KEY_Read();
            if (key3 == UP_KEY)
            {
                if (j == 0)
                {
                    j = 3;
                }
                else
                {
                    j--;
                }
                LCD_CLS();
            }
            else if (key3 == DOWN_KEY)
            {
                if (j == 3)
                {
                    j = 0;
                }
                else
                {
                    j++;
                }
                LCD_CLS();
            }
            else if (key3 == OK_KEY)
            {
                if (j == 0)
                {
                    l1 = -l1;
                    if (l1 == 1)
                        Led1On();
                    else
                        Led1Off();
                }
                else if (j == 1)
                {
                    l2 = -l2;
                    if (l2 == 1)
                        Led2On();
                    else
                        Led2Off();
                }
                else if (j == 2)
                {
                    f = -f;
                    if (f == 1)
                        FanOn();
                    else
                        FanOff();
                }
                else if (j == 3)
                {
                    b = -b;
                    if (b == 1)
                        BuzzerOn();
                    else
                        BuzzerOff();
                }
                LCD_CLS();
            }
            else if (key3 == ESC_KEY)
            {
                page = 1;
                LCD_CLS();
                break;
            }
        }*/
    }
}
