#include <STC89C5xRC.H>

#include "LCD1602.h"
void main()
{
    LCD_Init();

    LCD_ShowString(1, 1, "1903070324");
    LCD_ShowString(2, 1, "ljs");

    while (1)
        ;
}
