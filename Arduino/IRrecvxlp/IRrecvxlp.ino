#include <IRremote.h>

int LED = 10;
int brightness = 0;
long preCondition = 0x00; 
long nowCondition = 0x00; 
IRrecv irrecv(3);         
decode_results result;   

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();                    
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&result))           
  {
    irrecv.resume();       
}
