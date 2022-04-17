#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 11, 10, A1, A0, A2);
int R0 = A4;
int R1 = 8;
int R2 = 12;
int R3 = 6;
int C0 = 5;
int C1 = 7;
int C2 = 13;
int C3 = A3;
int pressed;
int state;
int StateTransEn;
int v1, v2, v3, op;

void setup()
{
  pinMode(R0, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(C0, INPUT_PULLUP);
  pinMode(C1, INPUT_PULLUP);
  pinMode(C2, INPUT_PULLUP);
  pinMode(C3, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(14, 1);
  lcd.print(0);
  v1 = 0;
  v2 = 0;
  StateTransEn = 1;
  state = 0;
}

void loop()
{
  pressed = 0;


  //ROW=0111
  digitalWrite(R0, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  if (digitalRead(C0) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=0,col=0");
    lcd.clear();
    lcd.setCursor(14, 1);
    lcd.print(0);
    pressed = 1;
    StateMachine(15);
  }
  if (digitalRead(C1) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=0,col=1");
    pressed = 1;
    StateMachine(14);
  }
  if (digitalRead(C2) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=0,col=2");
    pressed = 1;
    StateMachine(13);
  }
  if (digitalRead(C3) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=0,col=3");
    pressed = 1;
    StateMachine(12);
  }



  //ROW=1011
  digitalWrite(R0, HIGH);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  if (digitalRead(C0) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=1,col=0");
    pressed = 1;
    StateMachine(11);
  }
  if (digitalRead(C1) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=1,col=1");
    pressed = 1;
    StateMachine(10);
  }
  if (digitalRead(C2) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=1,col=2");
    pressed = 1;
    StateMachine(9);
  }
  if (digitalRead(C3) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=1,col=3");
    pressed = 1;
    StateMachine(8);
  }



  //ROW=1101
  digitalWrite(R0, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(R3, HIGH);
  if (digitalRead(C0) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=2,col=0");
    pressed = 1;
    StateMachine(7);
  }
  if (digitalRead(C1) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=2,col=1");
    pressed = 1;
    StateMachine(6);
  }
  if (digitalRead(C2) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=2,col=2");
    pressed = 1;
    StateMachine(5);
  }
  if (digitalRead(C3) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=2,col=3");
    pressed = 1;
    StateMachine(4);
  }


  //ROW=1110
  digitalWrite(R0, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, LOW);
  if (digitalRead(C0) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=3,col=0");
    pressed = 1;
    StateMachine(3);
  }
  if (digitalRead(C1) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=3,col=1");
    pressed = 1;
    StateMachine(2);
  }
  if (digitalRead(C2) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=3,col=2");
    pressed = 1;
    StateMachine(1);
  }
  if (digitalRead(C3) == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("row=3,col=3");
    pressed = 1;
    StateMachine(0);
  }
  if (pressed == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("             ");
    StateTransEn = 1;
  }
}
void StateMachine(int k)
{
  if (StateTransEn == 1)
  {
    switch (state)
    {
      case 0:
        v1 = 0;
        v2 = 0;
        if ((k >= 0) && (k <= 9))
        {
          state = 1;
          v1 = k;
        }
        break;
      case 1:
        if ((k >= 0) && (k <= 9))
        {
          v1 = v1 * 10 + k;
        }
        if ((k >= 10) && (k <= 13))
        {
          state = 2;
          op = k;
        }
        if (k == 15)
        {
          state = 0;
        }
        break;
      case 2:
        if ((k >= 10) && (k <= 13))
        {
          op = k;
        }
        if ((k >= 0) && (k <= 9))
        {
          state = 3;
          v2 = k;
        }
        if (k == 15)
        {
          state = 0;
        }
        break;
      case 3:
        if ((k >= 0) && (k <= 9))
        {
          v2 = v2 * 10 + k;
        }
        if (k == 14)
        {
          state = 4;
          switch (op)
          {
            case 10:
              v3 = v1 + v2;
              break;
            case 11:
              v3 = v1 - v2;
              break;
            case 12:
              v3 = v1 * v2;
              break;
            case 13:
              v3 = v1 / v2;
              break;
          }
        }
        if (k == 15)
        {
          state = 0;
        }
        break;
      case 4:
        if (k == 15)
        {
          state = 0;
        }
        break;
    }
    show();
    StateTransEn = 0;
  }
}
void show()
{
  lcd.setCursor(0, 1);
  lcd.print("             ");
  lcd.setCursor(14, 1);
  lcd.print(v3);
  lcd.setCursor(0, 0);
  if (state >= 1)
  {
    lcd.print(v1);
  }
  if (state >= 2)
  {
    switch (op)
    {
      case 10:
        lcd.print("+");
        break;
      case 11:
        lcd.print("-");
        break;
      case 12:
        lcd.print("*");
        break;
      case 13:
        lcd.print("/");
        break;
    }
  }
  if (state >= 3)
  {
    lcd.print(v2);
  }
  if (state >= 4)
  {
    lcd.print("=");
    lcd.print(v3);
  }
}
