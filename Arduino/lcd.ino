//跳线插CN5口

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 11, 10, A1, A0, A2);

void setup() {

  lcd.begin(16, 2);   //初始化16列2行lcd显示屏幕
  lcd.clear();        //清屏

  lcd.setCursor(0, 0);        //设定你要显示的文字的起始位置
  lcd.print("Hello World!");
  lcd.setCursor(2, 1);       //例如（14,0）就是第14列第1行显示
  lcd.print("Arduino");
  
}

void loop() {
    //loop中也可以使用lcd
  lcd.setCursor(0, 0);        //设定你要显示的文字的起始位置
  lcd.print("Hello World!");
  lcd.setCursor(2, 1);       //例如（14,0）就是第14列第1行显示
  lcd.print("Arduino");
  

}
