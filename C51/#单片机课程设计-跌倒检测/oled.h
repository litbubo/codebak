#include <STC89C5xRC.H>

#ifndef __OLED_H__
#define __OLED_H__
#define  uchar unsigned char 
#define  uint unsigned int 
#define OLED_CMD  0
#define OLED_DATA 1
#define OLED_MODE 0

#define SIZE 16
#define XLevelL		0x02
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  

void OLED_WR_Byte(unsigned dat,unsigned cmd);  
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);

void OLED_ShowChar(uchar x,uchar y,uchar chr,uchar Char_Size);
void OLED_ShowNum(uchar x,uchar y,uint num,uchar len,uchar size);
void OLED_ShowString(uchar x,uchar y, uchar *p,uchar Char_Size);	 
void OLED_Set_Pos(uchar x, uchar y);


void IIC_Wait_Ack();
#endif  
	 
