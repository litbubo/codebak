#ifndef __BSP_BEEP_H__
#define __BSP_BEEP_H__

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

void beep_init(void);
void beep_switch(int state);



#endif // !__BSP_BEEP_H__