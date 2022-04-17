#include "bsp_beep.h"
#include "cc.h"
#include "bsp_gpio.h"
/* BEEP初始化 */
void beep_init()
{
    gpio_pin_config_t beep;
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0);/* 复用为GPIO5_IO1 */
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0x10b0);

    /* GPIO初始化 */
    beep.direction = kGPIO_DigitalOutput;
    beep.output_Logic = 1;
    gpio_init(GPIO5, 1, &beep);
}

void beep_switch(int state)
{
    if(state == OFF)
        gpio_pinwrite(GPIO5, 1, 1);
    else if (state == ON)
        gpio_pinwrite(GPIO5, 1, 0);
}