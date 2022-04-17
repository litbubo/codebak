#ifndef __BSP_KEYFILTER_H__
#define __BSP_KEYFILTER_H__

#include "imx6u.h"

void keyfilter_init();
void filtertimer_init(uint32_t value);
void filtertimer_stop();
void filtertimer_restart(uint32_t value);
void epit1_filter_handler(uint32_t gicciar, void *param);
void gpio1_16_31_irqhandler(uint32_t gicciar, void *param);

#endif // !__KEYFILTER_H__
