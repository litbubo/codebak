#include "bsp_gpio.h"

void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config)
{
    if (config->direction == kGPIO_DigitalInput)
    {
        base->GDIR &= ~(1 << pin);
    }
    else
    {
        base->GDIR |= (1 << pin);
        /* 设置默认输出电平 */
        gpio_pinwrite(base, pin, config->output_Logic);
    }
    gpio_intconfig(base, pin, config->interrupt_Mode);
}

void gpio_pinwrite(GPIO_Type *base, int pin, int value)
{
    if (value == 0)
    {
        base->DR &= ~(1 << pin);
    }
    else
    {
        base->DR |= (1 << pin);
    }
}

int gpio_pinread(GPIO_Type *base, int pin)
{
    return ((base->DR >> pin) & 0x01);
}

/* 使能指定IO中断 */
void gpio_enableInt(GPIO_Type *base, int pin)
{
    base->IMR |= (1 << pin);
}

void gpio_disenableInt(GPIO_Type *base, int pin)
{
    base->IMR &= ~(1 << pin);
}

/* 清除中断标志位 */
void gpio_clearintflags(GPIO_Type *base, int pin)
{
    base->ISR |= (1 << pin);
}

void gpio_intconfig(GPIO_Type *base, int pin, gpio_interrupt_mode_t pin_intMode)
{
    volatile uint32_t *icr;
    uint32_t icrshit;

    icrshit = pin;
    base->EDGE_SEL &= ~(1 << pin);

    if (pin < 16)
    {
        icr = &(base->ICR1);
    }
    else
    {
        icr = &(base->ICR2);
        icrshit -= 16;
    }

    switch (pin_intMode)
    {
    case kGPIO_IntLowLevel:
        *icr &= ~(3 << (2 * icrshit));
        break;
    case kGPIO_IntHighLevel:
        *icr &= ~(3 << (2 * icrshit));
        *icr |= (1 << (2 * icrshit));
        break;
    case kGPIO_IntRisingEdge:
        *icr &= ~(3 << (2 * icrshit));
        *icr |= (2 << (2 * icrshit));
        break;
    case kGPIO_IntFallingEdge:
        *icr &= ~(3 << (2 * icrshit));
        *icr |= (3 << (2 * icrshit));
        break;
    case kGPIO_IntRisingOrFallingEdge:
        base->EDGE_SEL |= (1 << pin);
        break;
    default:
        break;
    }
}