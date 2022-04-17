#include "fsl_iomuxc.h"
#include "fsl_common.h"
#include "MCIMX6Y2.h"

#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_delay.h"

int main(void)
{
    clk_init();
    led_init();
    beep_init();
    /*初始化LED*/
    while (1)
    {
        beep_switch(ON);
        led_switch(LED0, ON);
        delay(1000);
        beep_switch(OFF);
        led_switch(LED0, OFF);
        delay(1000);
    }
    
    return 0;
}