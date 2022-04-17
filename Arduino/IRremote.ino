//跳线接口接 CN2

#include <IRremote.h>

IRrecv irrecv(3);         //设置红外接收引脚
decode_results results;   //保存结果

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();    // enable
}

void loop()
{
  if (irrecv.decode(&results))   //declde
  {
    Serial.println(results.value, HEX);

    if ((results.value == 0xFF6897))      //0按键
    {
          //此处写你的代码
    }
    if ((results.value == 0xFF30CF))      //1按键
    {
          //此处写你的代码
    }

    irrecv.resume();        //resume
  }
}
