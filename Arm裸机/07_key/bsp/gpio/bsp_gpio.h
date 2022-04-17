#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__

#include "fsl_iomuxc.h"
#include "fsl_common.h"
#include "MCIMX6Y2.h"
#include "cc.h"

/* 枚举类型和GPIO结构体 */
typedef enum _gpio_pin_direction
{
    kGPIO_DigitalInput = 0U,
    kGPIO_DigitalOutput = 1U,
}gpio_pin_direction_t;

typedef struct _gpio_pin_config
{
    gpio_pin_direction_t direction;
    uint8_t output_Logic;
}gpio_pin_config_t;

void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config);
void gpio_pinwrite(GPIO_Type *base, int pin, int value);
int gpio_pinread(GPIO_Type *base, int pin);

#endif /* __BSP_GPIO_H__ */