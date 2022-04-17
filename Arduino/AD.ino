#include <LiquidCrystal.h>
int respin = A3;   //定义模拟接口0
int ledpin = 5;  
int val = 0;     


LiquidCrystal lcd(2, 11, 10, A1, A0, A2);

void setup() 
{
  pinMode(ledpin,OUTPUT);  
  
  lcd.begin(16, 2);
  lcd.clear();    // 清屏
  lcd.print("Hello world!");
  delay(1000);
}

void loop()
{
  val = analogRead(respin);  //读取模拟接口0 的值，并将其赋给val
  lcd.clear();
  lcd.setCursor(0,0);   // 列0 行0
  lcd.print(val);    //显示出val 的值
  val = val / 4;
  lcd.setCursor(0,1);   // 列0 行0
  lcd.print(val);    //显示出val 的值
  analogWrite(ledpin, 255 - val);

  delay(1000);
}
