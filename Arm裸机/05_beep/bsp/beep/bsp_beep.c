#include "bsp_beep.h"
#include "cc.h"
/* BEEP初始化 */
void beep_init()
{
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0);/* 复用为GPIO5_IO1 */
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0x10b0);

    /* GPIO初始化 */
    GPIO5->GDIR |= (1 << 1);
    GPIO5->DR   |= (1 << 1);
}

void beep_switch(int state)
{
    if(state == OFF)
        GPIO5->DR |= (1 << 1);
    else if (state == ON)
        GPIO5->DR &= ~(1 << 1);
}