#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "LCD1602.h"
#include "Delayms.h"
#include "XPT2046.h"
/*
#define XPT2046_VBAT_8		0xAC    //1010 1100
#define XPT2046_AUX_8		0xEC	//1110 1100
#define XPT2046_XP_8		0x9C	//1001 1100
#define XPT2046_YP_8		0xDC	//1101 1100

#define XPT2046_VBAT_12		0xA4    //1010 0100
#define XPT2046_AUX_12		0xE4	//1110 0100
#define XPT2046_XP_12		0x94	//1001 0100
#define XPT2046_YP_12		0xD4	//1101 0100
*/

int main()
{
	LCD_Init();
	LCD_ShowString(1,1,"AIN0 AIN1 AIN2");
    while(1)
    {
        /*add your codes*/
		LCD_ShowNum(2, 1, XPT2046_ReadAD(XPT2046_XP_8),4);
		LCD_ShowNum(2, 6, XPT2046_ReadAD(XPT2046_YP_8),4);
		LCD_ShowNum(2, 11, XPT2046_ReadAD(XPT2046_VBAT_8),4);
    }
    return 0;
}