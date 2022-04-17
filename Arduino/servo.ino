int servoPin = 7;
int servoPos;
void setup() 
{
  pinMode(servoPin,OUTPUT);
}

void loop() //死循环体
{
  for (servoPos = 500; servoPos <= 2500; servoPos += 8)
  {
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(servoPos);
    digitalWrite(servoPin, LOW);
    delayMicroseconds(20000 - servoPos);
    delay(10);
  }
  for (servoPos = 2500; servoPos >= 500; servoPos -= 8)
  {
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(servoPos);
    digitalWrite(servoPin, LOW);
    delayMicroseconds(20000 - servoPos);
    delay(10);
  }
 }
