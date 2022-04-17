#ifndef __BSP_AP3216C_H__
#define __BSP_AP3216C_H__

#include "imx6u.h"

#define AP3216C_ADDR    	0X1E	/* AP3216C器件地址          */

/* AP3316C寄存器 */
#define AP3216C_SYSTEMCONG	0x00	/* 配置寄存器 			    */
#define AP3216C_INTSTATUS	0X01	/* 中断状态寄存器 			*/
#define AP3216C_INTCLEAR	0X02	/* 中断清除寄存器 			*/
#define AP3216C_IRDATALOW	0x0A	/* IR数据低字节 			*/
#define AP3216C_IRDATAHIGH	0x0B	/* IR数据高字节 			*/
#define AP3216C_ALSDATALOW	0x0C	/* ALS数据低字节 		    */
#define AP3216C_ALSDATAHIGH	0X0D	/* ALS数据高字节			*/
#define AP3216C_PSDATALOW	0X0E	/* PS数据低字节 			*/
#define AP3216C_PSDATAHIGH	0X0F	/* PS数据高字节 			*/

uint8_t ap3216c_readbyte(uint8_t addr, uint8_t reg);
void ap3216_init();
uint8_t ap3216c_readbyte(uint8_t addr, uint8_t reg);
uint8_t ap3216c_writebyte(uint8_t addr, uint8_t reg, uint8_t data);
void ap3216c_readdata(uint16_t *ir, uint16_t *ps, uint16_t *als);
#endif // !__BSP_AP3216C_H__
