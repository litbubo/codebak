#ifndef __BSP_RTC_H__
#define __BSP_RTC_H__

#include "imx6u.h"

/* 相关宏定义 */
#define SECONDS_IN_A_DAY        (86400) /* 一天86400秒	 	    */
#define SECONDS_IN_A_HOUR       (3600)  /* 一个小时3600秒 		*/
#define SECONDS_IN_A_MINUTE     (60)    /* 一分钟60秒  		 	*/
#define DAYS_IN_A_YEAR          (365)   /* 一年365天 			*/
#define YEAR_RANGE_START        (1970)  /* 开始年份1970年 		*/
#define YEAR_RANGE_END          (2099)  /* 结束年份2099年 		*/

/* 时间日期结构体 */
typedef struct rtc_datetime
{
    uint16_t year;  /* 范围为:1970 ~ 2099 		        */
    uint8_t month;  /* 范围为:1 ~ 12				    */
    uint8_t day;    /* 范围为:1 ~ 31 (不同的月，天数不同).*/
    uint8_t hour;   /* 范围为:0 ~ 23 			        */
    uint8_t minute; /* 范围为:0 ~ 59				    */
    uint8_t second; /* 范围为:0 ~ 59				    */
}rtc_datetime;

void rtc_init();
void rtc_enable();
void rtc_disenable();
uint64_t rtc_coverdate_to_seconds(rtc_datetime *datetime);
void rtc_settime(rtc_datetime *datetime);
uint64_t rtc_readseconds();
void rtc_readtime(rtc_datetime *datetime);
void rtc_convertseconds_to_datetime(uint64_t seconds, rtc_datetime *datetime);
uint8_t rtc_isleapyear(uint16_t year);

#endif // !__BSP_RTC_H__