
#include <IRremote.h>

int LED = 10;
int light = 1;
IRrecv irrecv(3);         //设置红外接收引脚
decode_results results;  //保存结果

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();    // enable
  pinMode(LED, OUTPUT);
}

void loop()
{
  analogWrite(LED, light);
  if (irrecv.decode(&results))   //declde
  {
    Serial.println(results.value, HEX);

    if ((results.value == 0xFF6897) && (light >= 1)) //0
    {
      light--;
    }
    if ((results.value == 0xFF30CF) && (light < 255)) //1
    {
      light++;
    }

    irrecv.resume();        //resume
  }
}
