#include "bsp_epit.h"
#include "bsp_int.h"
#include "bsp_led.h"
void epit_init(uint32_t frac, uint32_t value) 
{
    if(frac > 4095)
        frac = 4095;
    EPIT1->CR = 0x0;
    EPIT1->CR |= (1 << 1) | (1 << 2) | (1 << 3) | (frac << 4) | (1 << 24);
    EPIT1->LR = value;
    EPIT1->CMPR = 0x0;

    /* 初始化中断 */
    GIC_EnableIRQ(EPIT1_IRQn);
    system_register_irqhandler(EPIT1_IRQn, epit1_irq_handler, NULL);
    EPIT1->CR |= 1;
}

void epit1_irq_handler(uint32_t gicciar, void *param)
{
    static uint8_t status = 0;
    status = !status;
    if((EPIT1->SR & 1) == 1)
    {
        led_switch(LED0, status);
    }
    /* 清除中断标志位 */
    EPIT1->SR |= (1 << 0);
}