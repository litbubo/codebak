#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 11, 10, A1, A0, A2);

void setup() 
{
  lcd.begin(16, 2);
  lcd.clear();    // 清屏
  lcd.print("Hello world!");
  delay(1000);
}

void loop() 
{
  lcd.setCursor(6,0);   // 列6 行0
  lcd.print("Arduino!");
  lcd.setCursor(0,1);   // 列0 行1
  lcd.print(millis() / 1000); // 毫秒
}
