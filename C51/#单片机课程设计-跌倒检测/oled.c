
#include "oled.h"

#include "oledfont.h"
#include "delay.h"
#include "IIC.h"

//#include "delay.h"
//OLED的显存
//存放格式如下.
//[0]0 1 2 3 ... 127
//[1]0 1 2 3 ... 127
//[2]0 1 2 3 ... 127
//[3]0 1 2 3 ... 127
//[4]0 1 2 3 ... 127
//[5]0 1 2 3 ... 127
//[6]0 1 2 3 ... 127
//[7]0 1 2 3 ... 127

void OLED_WR_Byte(unsigned dat, unsigned cmd)
{
    if (cmd)
    {

        IIC_Write_Data(0x78, 0x40, dat);
    }
    else
    {
        IIC_Write_Data(0x78, 0x00, dat);
    }
}

void OLED_Set_Pos(uchar x, uchar y)
{   OLED_WR_Byte(0xb0+y,OLED_CMD);
    OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
    OLED_WR_Byte((x&0x0f),OLED_CMD);
}

void OLED_Display_On(void)
{
    OLED_WR_Byte(0X8D,OLED_CMD);
    OLED_WR_Byte(0X14,OLED_CMD);
    OLED_WR_Byte(0XAF,OLED_CMD);
}

void OLED_Display_Off(void)
{
    OLED_WR_Byte(0X8D,OLED_CMD);
    OLED_WR_Byte(0X10,OLED_CMD);
    OLED_WR_Byte(0XAE,OLED_CMD);
}

void OLED_Clear(void)
{
    uchar i,n;
    for(i=0; i<8; i++)
    {
        OLED_WR_Byte (0xb0+i,OLED_CMD);
        OLED_WR_Byte (0x00,OLED_CMD);
        OLED_WR_Byte (0x10,OLED_CMD);
        for(n=0; n<128; n++)OLED_WR_Byte(0,OLED_DATA);
    }
}
void OLED_On(void)
{
    uchar i,n;
    for(i=0; i<8; i++)
    {
        OLED_WR_Byte (0xb0+i,OLED_CMD); 
        OLED_WR_Byte (0x00,OLED_CMD); 
        OLED_WR_Byte (0x10,OLED_CMD);
        for(n=0; n<128; n++)OLED_WR_Byte(1,OLED_DATA);
    } 
}

void OLED_ShowChar(uchar x,uchar y,uchar chr,uchar Char_Size)
{
    uchar c=0,i=0;
    c=chr-' ';
    if(x>Max_Column-1) {
        x=0;
        y=y+2;
    }
    if(Char_Size ==16)
    {
        OLED_Set_Pos(x,y);
        for(i=0; i<8; i++)
            OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);
        OLED_Set_Pos(x,y+1);
        for(i=0; i<8; i++)
            OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);
    }
    else {
        OLED_Set_Pos(x,y);
        for(i=0; i<6; i++)
            OLED_WR_Byte(F6x8[c][i],OLED_DATA);

    }
}

uint oled_pow(uchar m,uchar n)
{
    uint result=1;
    while(n--)result*=m;
    return result;
}

void OLED_ShowNum(uchar x,uchar y,uint num,uchar len,uchar size2)
{
    uchar t,temp;
    uchar enshow=0;
    for(t=0; t<len; t++)
    {
        temp=(num/oled_pow(10,len-t-1))%10;
        if(enshow==0&&t<(len-1))
        {
            if(temp==0)
            {
                OLED_ShowChar(x+(size2/2)*t,y,' ',size2);
                continue;
            } else enshow=1;

        }
        OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2);
    }
}

void OLED_ShowString(uchar x,uchar y,uchar *chr,uchar Char_Size)
{
    uchar j=0;
    while (chr[j]!='\0')
    {   OLED_ShowChar(x,y,chr[j],Char_Size);
        x+=8;
        if(x>120) {
            x=0;
            y+=2;
        }
        j++;
    }
}

void OLED_Init(void)
{

    OLED_WR_Byte(0xAE,OLED_CMD);//--display off
    OLED_WR_Byte(0x00,OLED_CMD);//---set low column address
    OLED_WR_Byte(0x10,OLED_CMD);//---set high column address
    OLED_WR_Byte(0x40,OLED_CMD);//--set start line address
    OLED_WR_Byte(0xB0,OLED_CMD);//--set page address
    OLED_WR_Byte(0x81,OLED_CMD); // contract control
    OLED_WR_Byte(0xFF,OLED_CMD);//--128
    OLED_WR_Byte(0xA1,OLED_CMD);//set segment remap
    OLED_WR_Byte(0xA6,OLED_CMD);//--normal / reverse
    OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
    OLED_WR_Byte(0x3F,OLED_CMD);//--1/32 duty
    OLED_WR_Byte(0xC8,OLED_CMD);//Com scan direction
    OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset
    OLED_WR_Byte(0x00,OLED_CMD);//

    OLED_WR_Byte(0xD5,OLED_CMD);//set osc division
    OLED_WR_Byte(0x80,OLED_CMD);//

    OLED_WR_Byte(0xD8,OLED_CMD);//set area color mode off
    OLED_WR_Byte(0x05,OLED_CMD);//

    OLED_WR_Byte(0xD9,OLED_CMD);//Set Pre-Charge Period
    OLED_WR_Byte(0xF1,OLED_CMD);//

    OLED_WR_Byte(0xDA,OLED_CMD);//set com pin configuartion
    OLED_WR_Byte(0x12,OLED_CMD);//

    OLED_WR_Byte(0xDB,OLED_CMD);//set Vcomh
    OLED_WR_Byte(0x30,OLED_CMD);//

    OLED_WR_Byte(0x8D,OLED_CMD);//set charge pump enable
    OLED_WR_Byte(0x14,OLED_CMD);//

    OLED_WR_Byte(0xAF,OLED_CMD);//--turn on oled panel
}





























