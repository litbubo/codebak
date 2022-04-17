#include "fsl_iomuxc.h"
#include "fsl_common.h"
#include "MCIMX6Y2.h"

#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_delay.h"
#include "bsp_key.h"

int main(void)
{
    u8 i = 0;
    u8 led_state = OFF;
    u8 keyvalue = 0;
    u8 beep_state = OFF;

    clk_init();
    led_init();
    beep_init();
    key_init();
    /*初始化LED*/
    while (1)
    {
        keyvalue = get_key();
        if (keyvalue)
        {
            switch (keyvalue)
            {
            case KEY0_VALUE:
                beep_state = !beep_state;
                beep_switch(beep_state);
                break;
            default:
                break;
            }
        } 

        i++;
        if (i == 50)
        {
            i = 0;
            led_state = !led_state;
            led_switch(LED0, led_state);
        }
        delay(10);
    }

    return 0;
}