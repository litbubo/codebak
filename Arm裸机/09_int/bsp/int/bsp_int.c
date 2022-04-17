#include "bsp_int.h"

static uint32_t irqNesting;
/* 中断处理函数表 */
static sys_irq_handle_t irqTable[NUMBER_OF_INT_VECTORS];

void system_irqTable_init()
{
    uint8_t i = 0;
    irqNesting = 0;
    for (i = 0; i < NUMBER_OF_INT_VECTORS; i++)
    {
        irqTable[i].irq_handler = default_irqhandler;
        irqTable[i].user_param = NULL;
    }
}

/* 具体的中断处理函数system_irqhandler */
void system_irqhandler(uint32_t gicciar)
{
    /* 检查中断ID */
    uint32_t intNUm = gicciar & 0x3ff;
    if (intNUm == 1023 || intNUm >= NUMBER_OF_INT_VECTORS)
    {
        return;
    }
    irqNesting++;
    /* 根据中断ID号 ， 读取中断处理函数*/
    irqTable[intNUm].irq_handler(intNUm, irqTable[intNUm].user_param);
    irqNesting--;
}

/* 注册中断处理函数 */
void system_register_irqhandler(IRQn_Type irq, system_irq_handler_t handle, void *userParam)
{
    irqTable[irq].irq_handler = handle;
    irqTable[irq].user_param = userParam;
}

/* 中断初始化函数 */
void int_init()
{
    GIC_Init();

    /* 中断向量偏移设置 */
    __set_VBAR(0x87800000);
}

void default_irqhandler(uint32_t gicciar, void *userParam)
{
    while (1)
    {
        /* code */
    }
}