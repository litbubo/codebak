#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#define LED0    0

#include "fsl_iomuxc.h"
#include "fsl_common.h"
#include "MCIMX6Y2.h"

void led_init();
void led_on();
void led_close();
void led_switch(int led, int state);

#endif // !__BSP_LED_H__

