#include "bsp_keyfilter.h"
#include "bsp_gpio.h"
#include "bsp_int.h"
#include "bsp_beep.h"
void keyfilter_init()
{
    gpio_pin_config_t key_config;
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0); /* 复用为GPIO */
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0xf080);

    /* GPIO初始化 */
    key_config.direction = kGPIO_DigitalInput;
    key_config.interrupt_Mode = kGPIO_IntFallingEdge;
    gpio_init(GPIO1, 18, &key_config);

    GIC_EnableIRQ(GPIO1_Combined_16_31_IRQn);
    system_register_irqhandler(GPIO1_Combined_16_31_IRQn, (system_irq_handler_t)gpio1_16_31_irqhandler, NULL);
    gpio_enableInt(GPIO1, 18);
    filtertimer_init(66000000/100);
}

/* 初始化EPIT1 */
void filtertimer_init(uint32_t value)
{
    EPIT1->CR = 0x0;
    EPIT1->CR |= (1 << 1) | (1 << 2) | (1 << 3) | (0 << 4) | (1 << 24);
    EPIT1->LR = value;
    EPIT1->CMPR = 0x0;

    /* 初始化中断 */
    GIC_EnableIRQ(EPIT1_IRQn);
    system_register_irqhandler(EPIT1_IRQn, (system_irq_handler_t)epit1_filter_handler, NULL);
    //EPIT1->CR |= 1;
}

/* 定时关闭 */
void filtertimer_stop()
{
    EPIT1->CR &= ~(1 << 0);
}

void filtertimer_restart(uint32_t value)
{
    EPIT1->CR &= ~(1 << 0);
    EPIT1->LR = value;
    EPIT1->CR |= (1 << 0);
}

/* 定时器中断处理函数 */
void epit1_filter_handler(uint32_t gicciar, void *param)
{
    static uint8_t status = OFF;
    if(EPIT1->SR & (1 << 0))
    {
        filtertimer_stop();
        if(gpio_pinread(GPIO1, 18) == 0)
        {
            status = !status;
            beep_switch(status);
        }
    }
    EPIT1->SR |= (1 << 0);
}
/* 中断处理函数 */
void gpio1_16_31_irqhandler(uint32_t gicciar, void *param)
{
    filtertimer_restart(66000000/100);

    /* 清除中断标志 */
    gpio_clearintflags(GPIO1, 18);
}