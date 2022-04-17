#include "bsp_clk.h"

void clk_init()
{
    CCM->CCGR0 = 0xffffffff;
    CCM->CCGR1 = 0xffffffff;
    CCM->CCGR2 = 0xffffffff;
    CCM->CCGR3 = 0xffffffff;
    CCM->CCGR4 = 0xffffffff;
    CCM->CCGR5 = 0xffffffff;
    CCM->CCGR6 = 0xffffffff;
}

/* 初始化时钟 */
void imx6u_clkinit()
{
    uint32_t reg = 0;
    /* 初始化主频为 528MHz */
    if(((CCM->CCSR >> 2) & 0x01) == 0)
    {
        /* 切换系统时钟 */
        CCM->CCSR &= ~(1 << 8); /* osc clock */
        CCM->CCSR |= (1 << 2);
    }

    /* 设置PLL1 为1056MHz */
    CCM_ANALOG->PLL_ARM =  (1 << 13) | ((88 << 0) & 0x7f);
    CCM->CACRR = 1; /* 0:1freq 1:2freq */
    CCM->CCSR &= ~(1 << 2);  /* 设置pll1_sw_clk = PLL1 */

    /* 设置PLL2的4路PFD */
    reg = CCM_ANALOG->PFD_528;
    reg &= ~(0x3f3f3f3f);
    reg |= (32 << 24);
    reg |= (24 << 16);
    reg |= (16 << 8);
    reg |= (27 << 0);
    CCM_ANALOG->PFD_528 = reg;

    /* 设置PLL3的4路PFD */
    reg = 0;
    reg = CCM_ANALOG->PFD_480;
    reg &= ~(0x3f3f3f3f);
    reg |= (19 << 24);
    reg |= (17 << 16); 
    reg |= (16 << 8);
    reg |= (12 << 0);
    CCM_ANALOG->PFD_480 = reg;

    /* 设置AHB_CLK_ROOT=132MHZ */
    CCM->CBCMR &= ~(3 << 18);
    CCM->CBCMR |= (1 << 18);
    CCM->CBCMR &= ~(1 << 25);
    while(CCM->CDHIPR & (1 << 5));

#if 0
    CCM->CBCDR &= ~(7 << 10);
    CCM->CBCDR |= (2 << 10);
    while(CCM->CDHIPR & (1 << 1));
#endif
    /* IPG_CLK_ROOT = 66MHZ */
    CCM->CBCDR &= ~(3 << 8);
    CCM->CBCDR |= (1 << 8);

    /* PER_CLK_ROOT = 66MHZ */
    CCM->CSCMR1 &= ~(1 << 6);
    CCM->CSCMR1 &= ~(0X3F << 0);

}