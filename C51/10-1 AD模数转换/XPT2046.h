#ifndef __XPT2046_H__
#define __XPT2046_H__

#define XPT2046_VBAT_8		0xAC    //1010 1100
#define XPT2046_AUX_8		0xEC	//1110 1100
#define XPT2046_XP_8		0x9C	//1001 1100
#define XPT2046_YP_8		0xDC	//1101 1100

#define XPT2046_VBAT_12		0xA4    //1010 0100
#define XPT2046_AUX_12		0xE4	//1110 0100
#define XPT2046_XP_12		0x94	//1001 0100
#define XPT2046_YP_12		0xD4	//1101 0100

unsigned int XPT2046_ReadAD(unsigned char Command);

#endif

