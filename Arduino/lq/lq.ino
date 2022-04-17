int LED = 9;
int anl = 2;
int anm = 1;
int xl = 0;
int xm = 0;
int ld = 20;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(anl, INPUT_PULLUP);
  pinMode(anm, INPUT_PULLUP);
}

void loop()
{
  analogWrite(LED, ld);
  xl = digitalRead(anl);
  xm = digitalRead(anm);
  if (xl == 0)
  {
    if (ld < 255)
    {
      ld++;
    }
    delay(10);
  }
  if (xm == 0)
  {
    if (ld > 0)
    {
      ld--;
    }
    delay(10);
  }
}
