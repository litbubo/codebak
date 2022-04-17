#ifndef __BSP_EPIT_H__
#define __BSP_EPIT_H__

#include "imx6u.h"
void epit_init(uint32_t frac, uint32_t value); 
void epit1_irq_handler(uint32_t gicciar, void *param);

#endif // !__BSP_EPIT_H__
