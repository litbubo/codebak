#include <Servo.h>
Servo myservo, myservo2, myservo_dis;

char con = '6';

void setup()
{
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  //pinMode(3, OUTPUT);
  myservo.attach(9);
  myservo2.attach(10);
  myservo_dis.attach(8);
  myservo.write(100);
  myservo2.write(90);
  myservo_dis.write(90);
  //analogWrite(3, 85);
}

void loop()
{
  if (Serial.available() > 0)
    con = Serial.read();
  switch (con)
  {
    case '0':
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      digitalWrite(A3, 0);
      break;
    case '1':
      digitalWrite(A0, 1);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      digitalWrite(A3, 1);
      break;
    case '2':
      digitalWrite(A0, 0);
      digitalWrite(A1, 1);
      digitalWrite(A2, 1);
      digitalWrite(A3, 0);
      
      break;
    case '3':
      digitalWrite(A0, 1);
      digitalWrite(A1, 0);
      digitalWrite(A2, 1);
      digitalWrite(A3, 0);
    /*  delay(300);
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      digitalWrite(A3, 0);
      con = '0';*/
      break;
    case '4':
      digitalWrite(A0, 0);
      digitalWrite(A1, 1);
      digitalWrite(A2, 0);
      digitalWrite(A3, 1);
      /*
      delay(300);
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      digitalWrite(A3, 0);
      con = '0';*/
     case '5':          //左转
     for (int pos = 90; pos <= 150; pos += 1) 
    {
      myservo_dis.write(pos);              
      delay(15);                       
    }
     case'6':            //右转
      for (int pos = 150; pos >= 30; pos -= 1) 
    {
      myservo_dis.write(pos);             
      delay(15);                   
    }
     case'7'://回正
      for (int pos = 30; pos <= 90; pos += 1) 
    {
      myservo_dis.write(pos);             
      delay(15);                       
    }

      break;
  }
}
