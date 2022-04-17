#ifndef __BSP_KEY_H__
#define __BSP_KEY_H__

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

enum keyvalue
{
    KEY_NONE = 0,
    KEY0_VALUE,
};

void key_init();

int get_key();

#endif // !__BSP_KEY_H__
