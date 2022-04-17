#include <Servo.h>
Servo myservo;
char con, c;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  myservo.attach(10);
  myservo.write(80);
}

void loop()
{
  c = Serial.read();

  if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '0')
    con = c;
  switch (con)
  {
    case '1':
      digitalWrite(A0, 1);
      digitalWrite(A1, 0);
      digitalWrite(A2, 1);
      digitalWrite(A3, 0);
      break;

    case '2':
      digitalWrite(A0, 0);
      digitalWrite(A1, 1);
      digitalWrite(A2, 0);
      digitalWrite(A3, 1);
      break;
    case '3':
      myservo.write(45);
      break;
    case '4':
      myservo.write(115);
      break;
      case '5':
      myservo.write(80);
      break;
    case '0':
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      digitalWrite(A3, 0);
      myservo.write(80);
      break;


  }
}
