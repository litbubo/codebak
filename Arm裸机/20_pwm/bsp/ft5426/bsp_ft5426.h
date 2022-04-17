#ifndef __BSP_FT5426_H__
#define __BSP_FT5426_H__

/* 宏定义 */
#define FT5426_ADDR				0X38	/* FT5426设备地址 		*/

#define FT5426_DEVICE_MODE		0X00 	/* 模式寄存器 			*/
#define FT5426_IDGLIB_VERSION	0XA1 	/* 固件版本寄存器 			*/
#define FT5426_IDG_MODE			0XA4	/* 中断模式				*/
#define FT5426_TD_STATUS		0X02	/* 触摸状态寄存器 			*/
#define FT5426_TOUCH1_XH		0X03	/* 触摸点坐标寄存器,
										 * 一个触摸点用4个寄存器存储坐标数据*/
										 
#define FT5426_XYCOORDREG_NUM	30		/* 触摸点坐标寄存器数量 */
#define FT5426_INIT_FINISHED	1		/* 触摸屏初始化完成 			*/
#define FT5426_INIT_NOTFINISHED	0		/* 触摸屏初始化未完成 			*/

#define FT5426_TOUCH_EVENT_DOWN			0x00	/* 按下 		*/
#define FT5426_TOUCH_EVENT_UP			0x01	/* 释放 		*/
#define FT5426_TOUCH_EVENT_ON			0x02	/* 接触 		*/
#define FT5426_TOUCH_EVENT_RESERVED		0x03	/* 没有事件 */


#include "imx6u.h"

/* 触摸屏结构体 */
struct ft5426_dev_struc
{	
	unsigned char initfalg;		/* 触摸屏初始化状态 */
	unsigned char intflag;		/* 标记中断有没有发生 */
	unsigned char point_num;	/* 触摸点 		*/
	unsigned short x[5];		/* X轴坐标 	*/
	unsigned short y[5];		/* Y轴坐标 	*/

};

extern struct ft5426_dev_struc ft5426_dev;


void ft5426_init();
void gpio1_io09_irqhandler(uint32_t gicciar, void *param);
uint8_t ft5426_writebyte(uint8_t addr, uint8_t reg, uint8_t data);
uint8_t ft5426_readbyte(uint8_t addr, uint8_t reg);
void ft5426_read_len(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf);
void ft5426_read_tpcoord();


#endif // !__BSP_FT5426_H__
