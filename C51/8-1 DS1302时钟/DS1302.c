#include <STC89C5xRC.H>

sbit DS1302_SCLK = P3^6;
sbit DS1302_CE = P3^5;
sbit DS1302_IO = P3^4;

//寄存器写入地址/指令定义
#define DS1302_SECOND		0x80
#define DS1302_MINUTE		0x82
#define DS1302_HOUR			0x84
#define DS1302_DATE			0x86
#define DS1302_MONTH		0x88
#define DS1302_DAY			0x8A
#define DS1302_YEAR			0x8C
#define DS1302_WP			0x8E

//时间数组，索引0~6分别为年、月、日、时、分、秒、星期
char DS1302_Time[]= {21, 8, 10, 11, 46, 50, 2};

void DS1302_Init()
{
    DS1302_CE = 0;
    DS1302_SCLK = 0;
    DS1302_IO = 0;
}

void DS1302_WriteByte(unsigned char Command, unsigned char Data)
{
    unsigned char i;
    DS1302_CE = 1;
    for (i = 0; i<8; i++)
    {
        DS1302_IO = Command & (0x01<<i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    for (i = 0; i<8; i++)
    {
        DS1302_IO = Data & (0x01<<i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    DS1302_CE = 0;
    DS1302_IO = 0;
    DS1302_SCLK = 0;
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
    unsigned char i, Data = 0x00;
    Command |= 0x01;
    DS1302_CE = 1;
    for (i = 0; i<8; i++)
    {
        DS1302_IO = Command & (0x01<<i);
        DS1302_SCLK = 0;
        DS1302_SCLK = 1;
    }
    for (i = 0; i<8; i++)
    {
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
        if(DS1302_IO == 1)
        {
            Data |= (0x01<<i);
        }
    }
    DS1302_CE = 0;
    DS1302_IO = 0;
    DS1302_SCLK = 0;
    return Data;
}

void DS1302_SetTime()
{
	DS1302_WriteByte( DS1302_WP, 0x00 );
    DS1302_WriteByte( DS1302_YEAR,   (DS1302_Time[0]/10)*16 + DS1302_Time[0]%10 );
    DS1302_WriteByte( DS1302_MONTH,  (DS1302_Time[1]/10)*16 + DS1302_Time[1]%10 );
    DS1302_WriteByte( DS1302_DATE,   (DS1302_Time[2]/10)*16 + DS1302_Time[2]%10 );
    DS1302_WriteByte( DS1302_HOUR,   (DS1302_Time[3]/10)*16 + DS1302_Time[3]%10 );
    DS1302_WriteByte( DS1302_MINUTE, (DS1302_Time[4]/10)*16 + DS1302_Time[4]%10 );
    DS1302_WriteByte( DS1302_SECOND, (DS1302_Time[5]/10)*16 + DS1302_Time[5]%10 );
    DS1302_WriteByte( DS1302_DAY,    (DS1302_Time[6]/10)*16 + DS1302_Time[6]%10 );
	DS1302_WriteByte( DS1302_WP, 0x80 );
}

void DS1302_ReadTime()
{
    unsigned char temp;
	
    temp = DS1302_ReadByte( DS1302_YEAR );
    DS1302_Time[0] = temp/16*10 + temp%16;
	
    temp = DS1302_ReadByte( DS1302_MONTH );
    DS1302_Time[1] = temp/16*10 + temp%16;
	
    temp = DS1302_ReadByte( DS1302_DATE );
    DS1302_Time[2] = temp/16*10 + temp%16;
	
    temp = DS1302_ReadByte( DS1302_HOUR );
    DS1302_Time[3] = temp/16*10 + temp%16;
	
    temp = DS1302_ReadByte( DS1302_MINUTE );
    DS1302_Time[4] = temp/16*10 + temp%16;
	
    temp = DS1302_ReadByte( DS1302_SECOND );
    DS1302_Time[5] = temp/16*10 + temp%16;
	
    temp = DS1302_ReadByte( DS1302_DAY );
    DS1302_Time[6] = temp/16*10 + temp%16;
}