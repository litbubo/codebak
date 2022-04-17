#include "imx6u.h"

#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_delay.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"
#include "bsp_epit.h"
#include "bsp_keyfilter.h"

int main(void)
{
    //u8 i = 0;
    u8 led_state = OFF;
    //u8 keyvalue = 0;
    //u8 beep_state = OFF;

    int_init();
    system_irqTable_init();
    imx6u_clkinit();
    clk_init();
    led_init();
    delay_init();
    beep_init();
    //key_init();
    keyfilter_init();
    //exti_init();
    //epit_init(0, 33000000);
    /*初始化LED*/
    while (1)
    {
        led_state = !led_state;
        led_switch(LED0, led_state);
        delay_ms(1000);
        /*
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
        delay(10);*/
    }

    return 0;
}