#include "fsl_iomuxc.h"
#include "fsl_common.h"
#include "MCIMX6Y2.h"

#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_delay.h"

int main(void)
{
    clk_init();
    led_init();
    /*初始化LED*/
    while (1)
    {
        led_switch(LED0, 1);
        delay(1000);
        led_switch(LED0, 0);
        delay(1000);
    }
    
    return 0;
}