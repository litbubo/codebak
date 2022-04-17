int rNS = 9;
int yNS = 11;
int gNS = 13;
int rEW = 3;
int yEW = 5;
int gEW = 7;
int pA = A4;
int pB = 6;
int pC = 10;
int pD = A2;
int pE = 2;
int pF = A0;
int pG = 8;
int pDP = 12;
int pS1 = A5;
int pS2 = A3;
int pS3 = A1;
int pS4 = 4;
int t = 1000;

void setup() {
  pinMode(rNS,OUTPUT);
  pinMode(yNS,OUTPUT);
  pinMode(gNS,OUTPUT);
  pinMode(rEW,OUTPUT);
  pinMode(yEW,OUTPUT);
  pinMode(gEW,OUTPUT);
  pinMode(pA, OUTPUT);
  pinMode(pB, OUTPUT);
  pinMode(pC, OUTPUT);
  pinMode(pD, OUTPUT);
  pinMode(pE, OUTPUT);
  pinMode(pF, OUTPUT);
  pinMode(pG, OUTPUT);
  pinMode(pDP, OUTPUT);
  pinMode(pS1, OUTPUT);
  pinMode(pS2, OUTPUT);
  pinMode(pS3, OUTPUT);
  pinMode(pS4, OUTPUT);
  digitalWrite (rNS,HIGH);
  digitalWrite (yNS,HIGH);
  digitalWrite (gNS,HIGH);
  digitalWrite (rEW,HIGH);
  digitalWrite (yEW,HIGH);
  digitalWrite (gEW,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (rNS,LOW);
  digitalWrite (gEW,LOW);
  Show3();
  delay(1000);
  Show2();
  delay(1000);
  Show1();
  delay(1000);
  digitalWrite (rNS,HIGH);
  digitalWrite (gEW,HIGH);
  Show0();
  delay(1000);
  //digitalWrite (yNS,LOW);
  digitalWrite (yEW,LOW);
  Show1();
  delay(1000);
  //digitalWrite (yNS,HIGH);
  digitalWrite (yEW,HIGH);
  Show0();
  delay(1000);
  digitalWrite (gNS,LOW);
  digitalWrite (rEW,LOW);
  Show3();
  delay(1000);
  Show2();
  delay(1000);
  Show1();
  delay(1000);
  Show0();
  digitalWrite (gNS,HIGH);
  digitalWrite (rEW,HIGH);
  delay(1000);
  digitalWrite (yNS,LOW);
  //digitalWrite (yEW,LOW);
  Show1();
  delay(1000);
  Show0();
  digitalWrite (yNS,HIGH);
  //++digitalWrite (yEW,HIGH);
  Show0();
  delay(1000);
 
 
}

void Show3()
{
  digitalWrite(pA,0);
  digitalWrite(pB,0);
  digitalWrite(pC,0);
  digitalWrite(pD,0);
  digitalWrite(pE,1);
  digitalWrite(pF,1);
  digitalWrite(pG,0);
  digitalWrite(pDP,1);
  digitalWrite(pS1,0);
  digitalWrite(pS2,0);
  digitalWrite(pS3,0);
  digitalWrite(pS4,1);  
}

void Show2()
{
  digitalWrite(pA,0);
  digitalWrite(pB,0);
  digitalWrite(pC,1);
  digitalWrite(pD,0);
  digitalWrite(pE,0);
  digitalWrite(pF,1);
  digitalWrite(pG,0);
  digitalWrite(pDP,1);
  digitalWrite(pS1,0);
  digitalWrite(pS2,0);
  digitalWrite(pS3,0);
  digitalWrite(pS4,1);  
}

void Show1()
{
  digitalWrite(pA,1);
  digitalWrite(pB,0);
  digitalWrite(pC,0);
  digitalWrite(pD,1);
  digitalWrite(pE,1);
  digitalWrite(pF,1);
  digitalWrite(pG,1);
  digitalWrite(pDP,1);
  digitalWrite(pS1,0);
  digitalWrite(pS2,0);
  digitalWrite(pS3,0);
  digitalWrite(pS4,1);  
}

void Show0()
{
  digitalWrite(pA,0);
  digitalWrite(pB,0);
  digitalWrite(pC,0);
  digitalWrite(pD,0);
  digitalWrite(pE,0);
  digitalWrite(pF,0);
  digitalWrite(pG,1);
  digitalWrite(pDP,1);
  digitalWrite(pS1,0);
  digitalWrite(pS2,0);
  digitalWrite(pS3,0);
  digitalWrite(pS4,1);  
}
