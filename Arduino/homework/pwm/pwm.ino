int LED = 13;
int cycle = 10000; //设置脉宽周期的时间，单位微秒
float brightness = 20; //设置LED亮度，范围0-100

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (brightness != 0)
  {
    float bright = (brightness / 100) * cycle; //分配一个周期中，高低电平的持续时间
    digitalWrite(LED, HIGH);
    delayMicroseconds(bright);
    digitalWrite(LED, LOW);
    delayMicroseconds(cycle - bright);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}
