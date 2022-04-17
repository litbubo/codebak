//跳线插CN5口

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 11, 10, A1, A0, A2);

int trigPin = 6;
int echopin = 3;

unsigned long start;
unsigned long end;
unsigned long distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echopin, INPUT);
  digitalWrite(trigPin, LOW);

  Serial.begin(9600);
  Serial.println("开始");

  lcd.begin(16, 2);
  lcd.clear();

  attachInterrupt(1, Calculation, CHANGE);

}

void Calculation()
{
  unsigned long t = micros();
  if (digitalRead(3) == HIGH)
  {
    start  = t;
  }
  else
  {
    end = t;
  }
  if (end > start)
  {
    distance = (end - start) / 58;
  }
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  Serial.print(distance);
  Serial.println("cm");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance = ");
  lcd.setCursor(11, 0);
  lcd.print(distance, DEC);
  lcd.setCursor(14, 0);
  lcd.print("CM");

  delay(100);
}
