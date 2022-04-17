#include "stm32f10x.h"
#include "string.h"
#include "delay.h"

#include "pwm.h"
#include "UART.h"
#include "oled.h"
#include "Keypasswd.h"

uint8_t rev_pos = 0;
uint8_t passwd[6] = {1,2,3,4,5,6};
uint8_t passwd_temp[6] = {0};

void USART2_IRQHandler()
{
    uint8_t clear_rev;
    rev[rev_pos++] = USART_ReceiveData(USART2);

    if (rev[0] != '#')
    {
        for (clear_rev = 0; clear_rev < 17; clear_rev++)
            rev[clear_rev] = 0;
        rev_pos = 0;
    }

    if(rev_pos == 16 && rev[15] == '*')
    {
        rev[rev_pos] = 0;
        rev_pos = 0;

        if(strcmp( (char *)rev, ack_open) == 0)
        {
            USART_SendData(USART2, '1');
            TIM_SetCompare2(TIM3, 190);
            OLED_Clear() ;
            OLED_ShowString(0,0,(uint8_t *)"Face Gate",16);
            OLED_ShowString(0,2,(uint8_t *)"Open the door",16);
            GPIO_ResetBits(GPIOB,GPIO_Pin_0);
            delay_ms(100);
            GPIO_SetBits(GPIOB,GPIO_Pin_0);
        }

        if(strcmp( (char *)rev, ack_close) == 0)
        {
            USART_SendData(USART2, '0');
            TIM_SetCompare2(TIM3, 180);
            OLED_Clear() ;
            OLED_ShowString(0,0,(uint8_t *)"Face Gate",16);
            OLED_ShowString(0,2,(uint8_t *)"Close the door",16);
            GPIO_ResetBits(GPIOB,GPIO_Pin_0);
            delay_ms(100);
            GPIO_SetBits(GPIOB,GPIO_Pin_0);
        }

        if(strcmp( (char *)rev, ack_wifi) == 0)
        {
            OLED_Clear() ;
            OLED_ShowString(0,0,(uint8_t *)"Face Gate",16);
            OLED_ShowString(0,2,(uint8_t *)"WiFi Connected",16);
            GPIO_ResetBits(GPIOB,GPIO_Pin_0);
            delay_ms(100);
            GPIO_SetBits(GPIOB,GPIO_Pin_0);
        }

        for (clear_rev = 0; clear_rev < 17; clear_rev++)
            rev[clear_rev] = 0;
    }
    else if(rev_pos == 16 && rev[15] != '*')
    {
        for (clear_rev = 0; clear_rev < 17; clear_rev++)
            rev[clear_rev] = 0;
        rev_pos = 0;
    }
}


int main()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    uint32_t Key_temp;
    uint8_t clear_passwd;
    uint8_t lock_flag = 1;
    uint8_t Key_pos = 0;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    delay_init();
    UART2_Init(115200);
    TIM3_PWM_Init(199, 7199);
    OLED_Init();

    TIM_SetCompare2(TIM3, 180);

    OLED_Clear() ;
    OLED_ShowString(0,0,(uint8_t *)"Face Gate",16);
    OLED_ShowString(0,2,(uint8_t *)"Input Password",16);


    GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    GPIO_SetBits(GPIOB,GPIO_Pin_0);


    Keypasswd_Init();



    while(1)
    {  
        Key_temp = Key_Scan();
        if(Key_temp != KEY_NULL)
        {
            switch (Key_temp)
            {
            case 14:
                for(clear_passwd = 0; clear_passwd < 6; clear_passwd++)
                    passwd_temp[clear_passwd] = 0;
                Key_pos = 0;
                OLED_ShowString(0,2,(uint8_t *)"Input Password",16);
                OLED_ShowString(0,4,(uint8_t *)"              ",16);
                OLED_ShowString(0,6,(uint8_t *)"              ",16);
                break;

            case 15:
                for(clear_passwd = 0; clear_passwd < 6; clear_passwd++)
                    if(passwd[clear_passwd] != passwd_temp[clear_passwd])
                        lock_flag = 0;
                if(lock_flag == 1)
				{
                    OLED_ShowString(0,4,(uint8_t *)"WELCOME      ",16);
					TIM_SetCompare2(TIM3, 190);
				}
                else
				{
                    OLED_ShowString(0,4,(uint8_t *)"PASSWD WRONG!",16);
					TIM_SetCompare2(TIM3, 180);
				}
                lock_flag = 1;
                for(clear_passwd = 0; clear_passwd < 6; clear_passwd++)
                    passwd_temp[clear_passwd] = 0;
                break;

            case 10:
                TIM_SetCompare2(TIM3, 190);
                OLED_Clear() ;
                OLED_ShowString(0,0,(uint8_t *)"Face Gate",16);
                OLED_ShowString(0,2,(uint8_t *)"Open the door",16);
                break;

            case 11:

                TIM_SetCompare2(TIM3, 180);
                OLED_Clear();
                OLED_ShowString(0,0,(uint8_t *)"Face Gate",16);
                OLED_ShowString(0,2,(uint8_t *)"Close the door",16);
                break;

            case 12:
                OLED_Display_Off();
                break;

            case 13:
                OLED_Display_On();
                break;
			
            default:
				if (Key_pos < 6)
				{
					passwd_temp[Key_pos] = Key_temp;
					OLED_ShowChar(Key_pos*8, 6, '*', 16);
					Key_pos ++;
				}
				break;
            }
            GPIO_ResetBits(GPIOB,GPIO_Pin_0);
            delay_ms(100);
            GPIO_SetBits(GPIOB,GPIO_Pin_0);
        }
    }

}
