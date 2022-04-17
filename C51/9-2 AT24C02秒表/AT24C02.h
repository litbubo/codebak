#ifndef __AT24C02_H__
#define __AT24C02_H__

void AT24C02_WriteByte(unsigned char WORDADDRESS, unsigned char Data);

unsigned char AT24C02_ReadByte(unsigned char WORDADDRESS);

#endif