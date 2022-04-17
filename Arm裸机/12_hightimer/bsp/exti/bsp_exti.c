#include "bsp_exti.h"
#include "bsp_gpio.h"
#include "bsp_int.h"
#include "bsp_delay.h"
#include "bsp_beep.h"
/* 初始化外部中断 */
void exti_init()
{
    gpio_pin_config_t key_config;
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0); /* 复用为GPIO */
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0xf080);

    /* GPIO初始化 */
    key_config.direction = kGPIO_DigitalInput;
    key_config.interrupt_Mode = kGPIO_IntFallingEdge;
    gpio_init(GPIO1, 18, &key_config);

    GIC_EnableIRQ(GPIO1_Combined_16_31_IRQn);
    system_register_irqhandler(GPIO1_Combined_16_31_IRQn, gpio1_io18_irqhandler, NULL);
    gpio_enableInt(GPIO1, 18);
}

/* 中断处理函数 */
void gpio1_io18_irqhandler(uint32_t gicciar, void *param)
{
    static uint8_t status = 0;
    delay(10);
    if(gpio_pinread(GPIO1, 18) == 0)
    {
        status = !status;
        beep_switch(status);
    }

    /* 清除中断标志 */
    gpio_clearintflags(GPIO1, 18);
}