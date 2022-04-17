#ifndef __BSP_EXTI_H__
#define __BSP_EXTI_H__

#include "imx6u.h"
void exti_init();
void gpio1_io18_irqhandler(uint32_t gicciar, void *param);
#endif // !__BSP_EXTI_H__
