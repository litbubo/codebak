#ifndef __ADXL345_H__
#define __ADXL345_H__

#define uchar unsigned char
#define uint unsigned int

extern uchar BUF[8];
extern uchar ge, shi, bai, qian, wan;
extern int dis_data;

void Multiple_read_ADXL345(void);

void Init_ADXL345();

#endif