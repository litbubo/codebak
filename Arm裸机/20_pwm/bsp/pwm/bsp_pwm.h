#ifndef __BSP_PWM_H__
#define __BSP_PWM_H__

#include "imx6u.h"

/* 背光PWM结构体 */
struct backlight_dev_struc
{	
	unsigned char pwm_duty;		/* 占空比	*/
};

extern struct backlight_dev_struc pwm_dev;


void pwm_init();
void pwm1_setperiod_value(uint32_t value);
void pwm1_setduty(uint8_t duty);
void pwm_irqhandler(uint32_t gicciar, void *param);

#endif // !__BSP_PWM_H__
