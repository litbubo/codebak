#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Delayms.h"
#include "LCD1602.h"
#include "DS1302.h"
int main()
{
	LCD_Init();
	DS1302_Init();
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");
	LCD_ShowString(2,12,"Wek");
	DS1302_SetTime();
	while(1)
	{
		DS1302_ReadTime();
		LCD_ShowNum(1, 1, DS1302_Time[0], 2);
		LCD_ShowNum(1, 4, DS1302_Time[1], 2);
		LCD_ShowNum(1, 7, DS1302_Time[2], 2);
		LCD_ShowNum(2, 1, DS1302_Time[3], 2);
		LCD_ShowNum(2, 4, DS1302_Time[4], 2);
		LCD_ShowNum(2, 7, DS1302_Time[5], 2);
		LCD_ShowNum(2, 15, DS1302_Time[6], 1);
	}
    return 0;
}