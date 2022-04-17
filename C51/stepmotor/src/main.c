#include <STC89C5xRC.H>

char up[4] = {0x0c, 0x06, 0x03, 0x09};
int count = 0;

typedef unsigned int u16; //对数据类型进行声明定义
typedef unsigned char u8;

u8 IrValue[6];
u8 Time;

u8 DisplayData[8];
u8 code smgduan[17] = {
    0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
    0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0X76};
//0、1、2、3、4、5、6、7、8、9、A、b、C、d、E、F、H的显示码
void delay(u16 i)
{
    while (i--)
        ;
}

void DigDisplay()
{
    u8 i;
    for (i = 0; i < 3; i++)
    {
        switch (i) //位选，选择点亮的数码管，
        {
        case (0):
            P22 = 0;
            P23 = 0;
            P24 = 0;
            break; //显示第0位
        case (1):
            P22 = 1;
            P23 = 0;
            P24 = 0;
            break; //显示第1位
        case (2):
            P22 = 0;
            P23 = 1;
            P24 = 0;
            break; //显示第2位
        }
        P0 = DisplayData[2 - i]; //发送数据
        delay(100);              //间隔一段时间扫描
        P0 = 0x00;               //消隐
    }
}

/*******************************************************************************
* 函数名         : IrInit()
* 函数功能		   : 初始化红外线接收
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

void IrInit()
{
    IT0 = 1; //下降沿触发
    EX0 = 1; //打开中断0允许
    EA = 1;  //打开总中断

    P32 = 1; //初始化端口
}

/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
***/

void main(void)
{
    P1 = 0x00;
    EA = 1;      //允许CPU中断
    TMOD = 0x11; //设定时器0和1为16位模式1
    ET0 = 1;     //定时器0中断允许
    TH0 = 0xF8;
    TL0 = 0x30; //设定时每隔2ms中断一次
    IrInit();
    while (1)
    {
        if (P33 == 0 | 
            P31 == 0 | 
            (DisplayData[0] == 0x06 && DisplayData[1] == 0x7d) |
            (DisplayData[0] == 0x3f && DisplayData[1] == 0x39) )
        {
            TR0 = 1;
        }
        else
        {
            TR0 = 0;
            P1 = 0X00;
        }

        DisplayData[0] = smgduan[IrValue[2] / 16];
        DisplayData[1] = smgduan[IrValue[2] % 16];
        DisplayData[2] = smgduan[16];
        DigDisplay();
    }
}
//定时器0中断处理
void timeint(void) interrupt 1
{
    TH0 = 0xF8;
    TL0 = 0x30; //设定时每隔1ms中断一次
    if (P33 == 0|(DisplayData[0] == 0x06 && DisplayData[1] == 0x7d) )
    {
        if (count >= 4)
        {
            count = 0;
        }

        P1 = up[count++];
    }
    else if (P31 == 0 | (DisplayData[0] == 0x3f && DisplayData[1] == 0x39) )
    {

        P1 = up[count--];
        if (count < 0)
        {
            count = 3;
        }
    }
}

void ReadIr() interrupt 0
{
    u8 j, k;
    u16 err;
    Time = 0;
    delay(700);   //7ms
    if (P32 == 0) //确认是否真的接收到正确的信号
    {

        err = 1000; //1000*10us=10ms,超过说明接收到错误的信号
        /*当两个条件都为真是循环，如果有一个条件为假的时候跳出循环，免得程序出错的时
		侯，程序死在这里*/
        while ((P32 == 0) && (err > 0)) //等待前面9ms的低电平过去
        {
            delay(1);
            err--;
        }
        if (P32 == 1) //如果正确等到9ms低电平
        {
            err = 500;
            while ((P32 == 1) && (err > 0)) //等待4.5ms的起始高电平过去
            {
                delay(1);
                err--;
            }
            for (k = 0; k < 4; k++) //共有4组数据
            {
                for (j = 0; j < 8; j++) //接收一组数据
                {

                    err = 60;
                    while ((P32 == 0) && (err > 0)) //等待信号前面的560us低电平过去
                    {
                        delay(1);
                        err--;
                    }
                    err = 500;
                    while ((P32 == 1) && (err > 0)) //计算高电平的时间长度。
                    {
                        delay(10); //0.1ms
                        Time++;
                        err--;
                        if (Time > 30)
                        {
                            return;
                        }
                    }
                    IrValue[k] >>= 1; //k表示第几组数据
                    if (Time >= 8)    //如果高电平出现大于565us，那么是1
                    {
                        IrValue[k] |= 0x80;
                    }
                    Time = 0; //用完时间要重新赋值
                }
            }
        }
        if (IrValue[2] != ~IrValue[3])
        {
            return;
        }
    }
}
