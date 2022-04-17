#ifndef __BSP_DELAY_H__
#define __BSP_DELAY_H__


#include "fsl_iomuxc.h"
#include "fsl_common.h"
#include "MCIMX6Y2.h"

void delay_shorts(volatile unsigned int n);

void delay(volatile unsigned int n);


#endif // !__BSP_DELAY_H__