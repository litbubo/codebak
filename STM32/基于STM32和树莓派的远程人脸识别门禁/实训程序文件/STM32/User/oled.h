#ifndef __OLED_H
#define __OLED_H

#include "sys.h"
#include "stdlib.h"
#define OLED_MODE 0
#define SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF
#define X_WIDTH 	128
#define Y_WIDTH 	64

#define OLED_CMD  0	//Ð´ÃüÁî
#define OLED_DATA 1	//Ð´Êý¾Ý

void OLED_WR_Byte(uint8_t dat,uint8_t cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Init(void);
void OLED_Clear(void);

void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);
void OLED_ShowString(uint8_t x,uint8_t y, uint8_t *p,uint8_t Char_Size);
void OLED_Set_Pos(uint8_t x, uint8_t y);

#endif




