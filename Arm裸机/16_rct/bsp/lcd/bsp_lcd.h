#ifndef __BSP_LCD_H__
#define __BSP_LCD_H__

#include "imx6u.h"

/* LCD 显存首地址 */
#define LCD_FRAMEBUF_ADDR   (0x89000000)

/* 屏幕ID */
#define ATK4342		0X4342	/* 4.3寸480*272 	*/
#define ATK4384		0X4384	/* 4.3寸800*480 	*/
#define ATK7084		0X7084	/* 7寸800*480 		*/
#define ATK7016		0X7016	/* 7寸1024*600 		*/
#define ATK1018		0X1018	/* 10.1寸1280*800 	*/

/* 颜色 */
#define LCD_BLUE		  0x000000FF
#define LCD_GREEN		  0x0000FF00
#define LCD_RED 		  0x00FF0000
#define LCD_CYAN		  0x0000FFFF
#define LCD_MAGENTA 	  0x00FF00FF
#define LCD_YELLOW		  0x00FFFF00
#define LCD_LIGHTBLUE	  0x008080FF
#define LCD_LIGHTGREEN	  0x0080FF80
#define LCD_LIGHTRED	  0x00FF8080
#define LCD_LIGHTCYAN	  0x0080FFFF
#define LCD_LIGHTMAGENTA  0x00FF80FF
#define LCD_LIGHTYELLOW   0x00FFFF80
#define LCD_DARKBLUE	  0x00000080
#define LCD_DARKGREEN	  0x00008000
#define LCD_DARKRED 	  0x00800000
#define LCD_DARKCYAN	  0x00008080
#define LCD_DARKMAGENTA   0x00800080
#define LCD_DARKYELLOW	  0x00808000
#define LCD_WHITE		  0x00FFFFFF
#define LCD_LIGHTGRAY	  0x00D3D3D3
#define LCD_GRAY		  0x00808080
#define LCD_DARKGRAY	  0x00404040
#define LCD_BLACK		  0x00000000
#define LCD_BROWN		  0x00A52A2A
#define LCD_ORANGE		  0x00FFA500
#define LCD_TRANSPARENT   0x00000000

/* LCD 屏幕信息结构体 */
typedef struct tftlcd_typedef
{
    uint16_t height;    // 屏幕高度
    uint16_t width;     // 屏幕宽度
    uint8_t  pixsize;   // 每个像素占用字节数
    uint16_t vspw;
    uint16_t vbpd;
    uint16_t vfpd;
    uint16_t hspw;
    uint16_t hbpd;
    uint16_t hfpd;
    uint32_t framebuffer;   // 屏幕显存起始地址
    uint32_t forecolor;     // 前景色
    uint32_t backcolor;     // 背景色
}tftlcd_type;

extern tftlcd_type tftlcd_dev;

void lcd_init();
uint16_t lcd_readid();
void lcd_gpioinit();
void lcd_reset();
void lcd_noreset();
void lcd_enable();
void lcdclk_init(uint8_t loopdiv, uint8_t prediv, uint8_t div);
inline void lcd_drawpoint(uint16_t x, uint16_t y, uint32_t color);
inline uint32_t lcd_readpoint(uint16_t x, uint16_t y);
void lcd_clear(uint32_t color);
void lcd_fill(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint32_t color);

#endif // !__BSP_LCD_H__
