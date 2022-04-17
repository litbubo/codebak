#include "bsp_delay.h"
#include "bsp_int.h"
#include "bsp_led.h"

/* 高精度延迟初始化 */
void delay_init()
{
    GPT1->CR = 0;
    GPT1->CR |= 1 << 15;
    while ((GPT1->CR >> 15) & 0x01)
        ;
    /* 设置GPT1时钟源为IPG_CLK = 66MHZ，restart模式，从0开始计数 */
    GPT1->CR |= (1 << 1) | (1 << 6);

    /* 分频设置 */
    GPT1->PR = 65; //66分频
    GPT1->OCR[0] = 0xffffffff;
#if 0
    /* 配置比较输出通道1, 500ms */
    GPT1->OCR[0] = 1000000 / 2;
    /* 打开GPT1输出比较中断 */
    GPT1->IR |= 1 << 0;
    /* 设置GIC */
    GIC_EnableIRQ(GPT1_IRQn);
    system_register_irqhandler(GPT1_IRQn, (system_irq_handler_t)GPT1_irqhandler, NULL);
#endif
    GPT1->CR |= 1 << 0;
}

/* 微秒延时 */
void delay_us(uint32_t us)
{
    uint32_t old, new;
    uint32_t t = 0;
    old = GPT1->CNT;
    while (1)
    {
        new = GPT1->CNT;
        if (new != old)
        {
            if (new > old)
                t += new - old;
            else
                t += 0xffffffff - old + new;
            old = new;
            if (t > us)
                break;
        }
    }
}

/* 毫秒延迟 */
void delay_ms(uint32_t ms)
{
    while (ms--)
    {
        delay_us(1000);
    }
}

#if 0
/* GPT1中断服务函数 */
void GPT1_irqhandler(uint32_t gicciar, void *param)
{
    static uint8_t status = OFF;
    if ((GPT1->SR & (1 << 0)) == 1)
    {
        status = !status;
        led_switch(LED0, status);
    }
    GPT1->SR |= 1 << 0;
}
#endif

void delay_shorts(volatile unsigned int n)
{
    while (n--)
        ;
}

/*延时， 一次循环1ms，主频396Mhz */
void delay(volatile unsigned int n)
{
    while (n--)
    {
        delay_shorts(0x7ff);
    }
}