#ifndef __BSP_INT_H__
#define __BSP_INT_H__

#include "imx6u.h"

/* 定义中断处理函数 */
typedef void (*system_irq_handler_t)(uint32_t gicciar, void *param);

/* 中断处理函数结构体 */
typedef struct _sys_irq_handle
{
    system_irq_handler_t irq_handler;
    void *user_param;
} sys_irq_handle_t;

void int_init();
void default_irqhandler(uint32_t gicciar, void *userParam);
void system_irqTable_init();
void system_register_irqhandler(IRQn_Type irq, system_irq_handler_t handle, void *userParam);
void system_irqhandler(uint32_t gicciar);

#endif // !__BSP_INT_H__
