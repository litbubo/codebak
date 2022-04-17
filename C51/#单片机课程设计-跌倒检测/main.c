#include <STC89C5xRC.H>
#include <INTRINS.H>

#include "delay.h"
#include "ADXL345.h"
#include "oled.h"

bit flag = 1;
int count = 0;

void conversion(uint temp_data)
{
    wan = temp_data / 10000;
    temp_data = temp_data % 10000;
    qian = temp_data / 1000;
    temp_data = temp_data % 1000;
    bai = temp_data / 100;
    temp_data = temp_data % 100;
    shi = temp_data / 10;
    temp_data = temp_data % 10;
    ge = temp_data;
}

void Timer0_Init()
{
    TMOD |= 0x01;
    TMOD &= 0xF1;
    TL0 = 64536 % 256;
    TH0 = 64536 / 256;
    EA = 1;
    ET0 = 1;
    TR0 = 0;
}

void Timer1_Init()
{
    TMOD |= 0x10;
    TMOD &= 0x1F;
    TL1 = 64536 % 256;
    TH1 = 64536 / 256;
    EA = 1;
    ET1 = 1;
    TR1 = 0;
}

void Key_Init()
{
    TCON |= 0x05;
    EX0 = 1;
    EX1 = 1;
}

void Dev_Init()
{
    Timer0_Init();
	Timer1_Init();
    Key_Init();
    Init_ADXL345();
    OLED_Init();
    OLED_Clear();
}

void Timer0_Inter() interrupt 1
{
    TL0 = 64536 % 256;
    TH0 = 64536 / 256;
    P04 = ~P04;
}

void Timer1_Inter() interrupt 3
{
    TL1 = 64536 % 256;
    TH1 = 64536 / 256;
    count++;
	if(count == 2000)
	{
		count = 0;
		TR0 = 1;
		TR1 = 0;
	}
}

void Key1_Inter() interrupt 0
{
    TR0 = 0;
	count = 0;
}

void Key2_Inter() interrupt 2
{
    if(flag == 1)
		OLED_Display_Off();
	else
		OLED_Display_On();
	flag = ~flag;
}

void Data_Deal(uchar sel)
{
	float temp;
	dis_data = (BUF[sel + 1] << 8) + BUF[sel];
	if (dis_data < 0)
	{
		dis_data = -dis_data;
	}
	temp = (float)dis_data * 3.9;
	
	if (sel == 4 && (((int)temp% 10000) < 300))
	{
		TR1 = 1;
		OLED_ShowString(0, 6, "Warning", 16);
	}
	else if (sel == 4 && (((int)temp% 10000) >= 300))
	{
		OLED_ShowString(0, 6, "          ", 16);
		TR1 = 0;
		count = 0;
		TR0 = 0;
	}
	conversion(temp);
}

int main()
{

    Dev_Init();
	
	OLED_ShowString(0, 0, "Fall Detection", 16);
	OLED_ShowString(0, 2, "System", 16);
	OLED_ShowString(0, 4, "Start", 16);
	Delayms(500);
	OLED_Clear();
	
	OLED_ShowString(0, 0, "wait...", 16);
	Delayms(500);
	OLED_Clear();
	
	OLED_ShowString(0, 0, "fall detection", 16);
    OLED_ShowString(0, 2, "X:", 16);
    OLED_ShowString(64, 2, "Y:", 16);
    OLED_ShowString(0, 4, "Z:", 16);

	
    while (1)
    {
		if (flag == 1)
		{
			Multiple_read_ADXL345();
			
			Data_Deal(0);
			OLED_ShowNum(15, 2, qian, 1, 16);
			OLED_ShowString(23, 2, ".", 16);
			OLED_ShowNum(30, 2, bai, 1, 16);
			OLED_ShowNum(40, 2, shi, 1, 16);
			
			Data_Deal(2);
			OLED_ShowNum(80, 2, qian, 1, 16);
			OLED_ShowString(88, 2, ".", 16);
			OLED_ShowNum(95, 2, bai, 1, 16);
			OLED_ShowNum(103, 2, shi, 1, 16);
			
			Data_Deal(4);
			OLED_ShowNum(15, 4, qian, 1, 16);
			OLED_ShowString(23, 4, ".", 16);
			OLED_ShowNum(30, 4, bai, 1, 16);
			OLED_ShowNum(40, 4, shi, 1, 16);
		}
    }

    return 0;
}