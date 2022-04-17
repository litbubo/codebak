#include "IIC.h"
#include "stm32f10x.h"

void IIC_IO_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_SetBits(GPIOA,GPIO_Pin_5|GPIO_Pin_6);
}

void IIC_Start(void)
{

    OLED_SCLK_Set();
    OLED_SDIN_Set();
    OLED_SDIN_Clr();
    OLED_SCLK_Clr();
}


void IIC_Stop(void)
{
    OLED_SCLK_Set();
    OLED_SDIN_Clr();
    OLED_SDIN_Set();

}

void IIC_Wait_Ack(void)
{
    OLED_SCLK_Set() ;
    OLED_SCLK_Clr();
}

void Write_IIC_Byte(uint8_t IIC_Byte)
{
    uint8_t i;
    uint8_t m,da;
    da=IIC_Byte;
    OLED_SCLK_Clr();
    for(i=0; i<8; i++)
    {
        m=da;
        m=m&0x80;
        if(m==0x80)
        {
            OLED_SDIN_Set();
        }
        else
            OLED_SDIN_Clr();
        da=da<<1;
        OLED_SCLK_Set();
        OLED_SCLK_Clr();
    }


}

void Write_IIC_Command(uint8_t IIC_Command)
{
    IIC_Start();
    Write_IIC_Byte(0x78);
    IIC_Wait_Ack();
    Write_IIC_Byte(0x00);
    IIC_Wait_Ack();
    Write_IIC_Byte(IIC_Command);
    IIC_Wait_Ack();
    IIC_Stop();
}

void Write_IIC_Data(uint8_t IIC_Data)
{
    IIC_Start();
    Write_IIC_Byte(0x78);
    IIC_Wait_Ack();
    Write_IIC_Byte(0x40);
    IIC_Wait_Ack();
    Write_IIC_Byte(IIC_Data);
    IIC_Wait_Ack();
    IIC_Stop();
}
