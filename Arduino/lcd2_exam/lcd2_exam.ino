//跳线插CN5口

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 11, 10, A1, A0, A2);
int i = 0;

void setup() {

  lcd.begin(16, 2);   //初始化16列2行lcd显示屏幕
  lcd.clear();        //清屏

}

void loop() {
  for (i = 0; i < 16; i++)
  {
    lcd.setCursor(i, 0);        //设定你要显示的文字的起始位置
    lcd.print("*");
    delay(1000);
  }
  i -= 1;
  for (; i >= 0; i--)
  {
    lcd.setCursor(i, 0);        //设定你要显示的文字的起始位置
    lcd.print(" ");
    delay(1000);
  }



}
