#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__

#include "fsl_iomuxc.h"
#include "fsl_common.h"
#include "MCIMX6Y2.h"
#include "cc.h"

/* 中断触发类型 */
typedef enum _gpio_interrupt_mode
{
    kGPIO_NoIntmode = 0U,              /* 无中断功能 */
    kGPIO_IntLowLevel = 1U,            /* 低电平触发	*/
    kGPIO_IntHighLevel = 2U,           /* 高电平触发 */
    kGPIO_IntRisingEdge = 3U,          /* 上升沿触发	*/
    kGPIO_IntFallingEdge = 4U,         /* 下降沿触发 */
    kGPIO_IntRisingOrFallingEdge = 5U, /* 上升沿和下降沿都触发 */
} gpio_interrupt_mode_t;

/* 枚举类型和GPIO结构体 */
typedef enum _gpio_pin_direction
{
    kGPIO_DigitalInput = 0U,
    kGPIO_DigitalOutput = 1U,
} gpio_pin_direction_t;

typedef struct _gpio_pin_config
{
    gpio_pin_direction_t direction;
    uint8_t output_Logic;
    gpio_interrupt_mode_t interrupt_Mode;
} gpio_pin_config_t;

void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config);
void gpio_pinwrite(GPIO_Type *base, int pin, int value);
int gpio_pinread(GPIO_Type *base, int pin);
void gpio_enableInt(GPIO_Type *base, int pin);
void gpio_disenableInt(GPIO_Type *base, int pin);
void gpio_clearintflags(GPIO_Type *base, int pin);
void gpio_intconfig(GPIO_Type *base, int pin, gpio_interrupt_mode_t pin_intMode);

#endif /* __BSP_GPIO_H__ */