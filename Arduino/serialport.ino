int val;
int ledpin = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}
void loop()
{
  val = Serial.read();
  if (val == 'A')
  {
    digitalWrite(ledpin, HIGH);
    Serial.write(val);
    Serial.print(" ");
    Serial.print(val);
    Serial.println(" turn on!");
  }
  else
  {
    if (val == 'B')
    {
      digitalWrite(ledpin, LOW);
      Serial.write(val);
      Serial.print(" ");
      Serial.print(val);
      Serial.println(" turn off!");
    }
    else
    {
      Serial.write(val);
      Serial.print(" ");
      Serial.println(val);
    }
  }
  delay(1000);
}
