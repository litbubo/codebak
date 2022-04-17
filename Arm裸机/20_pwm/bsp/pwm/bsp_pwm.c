#include "bsp_pwm.h"
#include "bsp_int.h"

struct backlight_dev_struc pwm_dev;

void pwm_init()
{
    // IO 初始化
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO08_PWM1_OUT, 0); /* 复用为GPIO */
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO08_PWM1_OUT, 0xb090);

    // PWM 初始化
    // 时钟源66 MHz， 66分频
    PWM1->PWMCR = 0;
    PWM1->PWMCR|= (1 << 16) | (65 << 4) | (1 << 26);

    pwm1_setperiod_value(1000);
    pwm_dev.pwm_duty = 50;
    pwm1_setduty(pwm_dev.pwm_duty);
    pwm1_setduty(pwm_dev.pwm_duty);
    pwm1_setduty(pwm_dev.pwm_duty);
    pwm1_setduty(pwm_dev.pwm_duty);

    // 使能 FIFO 中断
    PWM1->PWMIR = 1 << 0;
    GIC_EnableIRQ(PWM1_IRQn);
    system_register_irqhandler(PWM1_IRQn, (system_irq_handler_t)pwm_irqhandler, NULL);
    PWM1->PWMSR = 0xff;

    PWM1->PWMCR |= 1 << 0;
}

void pwm1_setperiod_value(uint32_t value)
{
    if(value < 2)
    {
        value = 2;
    }
    else
    {
        value -= 2;
    }
    PWM1->PWMPR = (value & 0xffff);
}


void pwm1_setduty(uint8_t duty)
{
    uint16_t period;
    uint16_t sample;

    pwm_dev.pwm_duty = duty;
    period = PWM1->PWMPR + 2;
    sample = (uint16_t)(period * (pwm_dev.pwm_duty / 100.0f));
    PWM1->PWMSAR = (sample & 0xffff);
}

/* 中断处理函数 */
void pwm_irqhandler(uint32_t gicciar, void *param)
{
    if(PWM1->PWMSR & (1 << 3))
    {
        pwm1_setduty(pwm_dev.pwm_duty);
        PWM1->PWMSR |= 1 << 3;
    }
}