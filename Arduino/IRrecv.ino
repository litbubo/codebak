#include <IRremote.h>

int LED=13;        
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
 if (irrecv.decode(&results))   //declde
 {
    Serial.println(results.value, HEX);
    if (results.value == 0xFF6897)    //0
    {
      digitalWrite(LED, 1);
    }
    if (results.value == 0xFF30CF)    //1
    {
      digitalWrite(LED, 0);
    }
    
    irrecv.resume();        //resume
 }
}
