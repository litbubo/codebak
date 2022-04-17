#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "LCD1602.h"
#include "Key.h"
#include "Delayms.h"
#include "AT24C02.h"

int main()
{
	char i = 1;
    LCD_Init();
	AT24C02_WriteByte(1, 89);
	Delayms(5);
	i = AT24C02_ReadByte(1);
    while(1)
    {
        /*add your codes*/
		LCD_ShowNum(1,1,i,2);
    }
    return 0;
}