#include "bsp_i2c.h"

void i2c_init(I2C_Type *base)
{
    base->I2CR &= ~(1 << 7);  // 关闭 IIC
    base->IFDR = 0x15;        // 640 分频 
    base->I2CR |= (1 << 7);   // 打开 IIC 
}
 
uint8_t i2c_master_start(I2C_Type *base, uint8_t address, enum i2c_direction direction)
{
    if (base->I2SR & (1 << 5))   // IIC 忙
        return 1;
    base->I2CR |= (1 << 5) | (1 << 4);

    // 产生 start 信号
    base->I2DR = ((uint32_t)address << 1) | 
                    (direction == kI2C_Read ? 1 : 0);
    return 0;
}

uint8_t i2c_master_stop(I2C_Type *base)
{
    uint16_t timeout = 0xFFFF;
    base->I2CR &= ~( (1 << 5) | (1 << 4) | (1 << 3) );

    while ((base->I2SR & (1 << 5)))
    {
        timeout --;
        if (timeout == 0)
            return I2C_STATUS_TIMEOUT;
    }
    return I2C_STATUS_OK;
}

/* 重复 start 信号 */
uint8_t i2c_master_restart(I2C_Type *base, uint8_t address, enum i2c_direction  direction)
{
    if (base->I2SR & (1 << 5) && ((base->I2CR & (1 << 5)) == 0))   // IIC 忙
        return 1;
    base->I2CR |= (1 << 4) | (1 << 2);
    // 产生 start 信号
    base->I2DR = ((uint32_t)address << 1) | 
                    (direction == kI2C_Read ? 1 : 0);
    return 0;
}

uint8_t i2c_check_and_clear_error(I2C_Type *base, uint32_t status)
{
    if (status & (1 << 4))
    {
        base->I2SR &= ~(1 << 4);
        base->I2CR &= ~(1 << 7);
        base->I2CR |=  (1 << 7);
        return I2C_STATUS_ARBITRATIONLOST;
    }
    else if (status & (1 << 0))
    {
        return I2C_STATUS_NAK;
    }
    return I2C_STATUS_OK;
}

void i2c_master_write(I2C_Type *base, const uint8_t* buf, uint32_t len)
{
    while ( !(base->I2SR & (1 << 7)) );

    base->I2SR &= ~(1 << 1);
    base->I2CR |=  (1 << 4);

    while (len--)
    {
        base->I2DR = *buf++;
        while( !(base->I2SR & (1 << 1)) );
        base->I2SR &= ~(1 << 1);
        if(i2c_check_and_clear_error(base, base->I2SR))
            break; 
    }
    base->I2SR &= ~(1 << 1);
    i2c_master_stop(base);
}

void i2c_master_read(I2C_Type *base, uint8_t* buf, uint32_t len)
{
    volatile uint8_t dummy = 0;
    dummy ++;

    while ( !(base->I2SR & (1 << 7)) );
    base->I2SR &= ~(1 << 1);
    base->I2CR &= ~((1 << 4) | (1 << 3));
    if(len == 1)
    {
        base->I2CR |= (1 << 3);
    }

    dummy = base->I2DR;

    while (len --)
    {
        while( !(base->I2SR & (1 << 1)) );
        base->I2SR &= ~(1 << 1);
        if(len == 1)
        {
            base->I2CR |= (1 << 3);
        }
        if(len == 0)
        {
            i2c_master_stop(base);
        }
        *buf++ = base->I2DR;
    }
    
}


/*
 * @description	: I2C数据传输，包括读和写
 * @param - base: 要使用的IIC
 * @param - xfer: 传输结构体
 * @return 		: 传输结果,0 成功，其他值 失败;
 */
unsigned char i2c_master_transfer(I2C_Type *base, struct i2c_transfer *xfer)
{
	unsigned char ret = 0;
	 enum i2c_direction direction = xfer->direction;	

	base->I2SR &= ~((1 << 1) | (1 << 4));			/* 清除标志位 */

	/* 等待传输完成 */
	while(!((base->I2SR >> 7) & 0X1)){}; 

	/* 如果是读的话，要先发送寄存器地址，所以要先将方向改为写 */
    if ((xfer->subaddressSize > 0) && (xfer->direction == kI2C_Read))
    {
        direction = kI2C_Write;
    }

	ret = i2c_master_start(base, xfer->slaveAddress, direction); /* 发送开始信号 */
    if(ret)
    {	
		return ret;
	}

	while(!(base->I2SR & (1 << 1))){};			/* 等待传输完成 */

    ret = i2c_check_and_clear_error(base, base->I2SR);	/* 检查是否出现传输错误 */
    if(ret)
    {
      	i2c_master_stop(base); 						/* 发送出错，发送停止信号 */
        return ret;
    }
	
    /* 发送寄存器地址 */
    if(xfer->subaddressSize)
    {
        do
        {
			base->I2SR &= ~(1 << 1);			/* 清除标志位 */
            xfer->subaddressSize--;				/* 地址长度减一 */
			
            base->I2DR =  ((xfer->subaddress) >> (8 * xfer->subaddressSize)); //向I2DR寄存器写入子地址
  
			while(!(base->I2SR & (1 << 1)));  	/* 等待传输完成 */

            /* 检查是否有错误发生 */
            ret = i2c_check_and_clear_error(base, base->I2SR);
            if(ret)
            {
             	i2c_master_stop(base); 				/* 发送停止信号 */
             	return ret;
            }  
        } while ((xfer->subaddressSize > 0) && (ret == I2C_STATUS_OK));

        if(xfer->direction == kI2C_Read) 		/* 读取数据 */
        {
            base->I2SR &= ~(1 << 1);			/* 清除中断挂起位 */
            i2c_master_restart(base, xfer->slaveAddress, kI2C_Read); /* 发送重复开始信号和从机地址 */
    		while(!(base->I2SR & (1 << 1))){};/* 等待传输完成 */

            /* 检查是否有错误发生 */
			ret = i2c_check_and_clear_error(base, base->I2SR);
            if(ret)
            {
             	ret = I2C_STATUS_ADDRNAK;
                i2c_master_stop(base); 		/* 发送停止信号 */
                return ret;  
            }
           	          
        }
    }	


    /* 发送数据 */
    if ((xfer->direction == kI2C_Write) && (xfer->dataSize > 0))
    {
    	i2c_master_write(base, xfer->data, xfer->dataSize);
	}

    /* 读取数据 */
    if ((xfer->direction == kI2C_Read) && (xfer->dataSize > 0))
    {
       	i2c_master_read(base, xfer->data, xfer->dataSize);
	}
	return 0;	
}