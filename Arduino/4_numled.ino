//跳线接CN1引脚  注意数码管的共阴极还是共阳极  不同的板子接法不同
int pA = A4;   //12根引脚 前8根为字形码引脚
int pB = 6;
int pC = 10;
int pD = A2;
int pE = 2;
int pF = A0;
int pG = 8;
int pDP = 12;

int pS1 = A5;   //12根引脚 后4根为位选引脚
int pS2 = A3;
int pS3 = A1;
int pS4 = 4;

void setup() {
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
}

void loop() {
  Show3();
  delay(5);
  Show2();
  delay(5);
  Show1();
  delay(5);
  Show0();
  delay(5);
}

void Show3()
{
  digitalWrite(pA,1);
  digitalWrite(pB,1);
  digitalWrite(pC,1);
  digitalWrite(pD,1);
  digitalWrite(pE,0);
  digitalWrite(pF,0);
  digitalWrite(pG,1);
  digitalWrite(pDP,0);
  digitalWrite(pS1,1);
  digitalWrite(pS2,1);
  digitalWrite(pS3,1);
  digitalWrite(pS4,0);  
}

void Show2()
{
  digitalWrite(pA,1);
  digitalWrite(pB,1);
  digitalWrite(pC,0);
  digitalWrite(pD,1);
  digitalWrite(pE,1);
  digitalWrite(pF,0);
  digitalWrite(pG,1);
  digitalWrite(pDP,0);
  digitalWrite(pS1,1);
  digitalWrite(pS2,1);
  digitalWrite(pS3,0);
  digitalWrite(pS4,1);  
}

void Show1()
{
  digitalWrite(pA,0);
  digitalWrite(pB,1);
  digitalWrite(pC,1);
  digitalWrite(pD,0);
  digitalWrite(pE,0);
  digitalWrite(pF,0);
  digitalWrite(pG,0);
  digitalWrite(pDP,0);
  digitalWrite(pS1,1);
  digitalWrite(pS2,0);
  digitalWrite(pS3,1);
  digitalWrite(pS4,1);  
}

void Show0()
{
  digitalWrite(pA,1);
  digitalWrite(pB,1);
  digitalWrite(pC,1);
  digitalWrite(pD,1);
  digitalWrite(pE,1);
  digitalWrite(pF,1);
  digitalWrite(pG,0);
  digitalWrite(pDP,0);
  digitalWrite(pS1,0);
  digitalWrite(pS2,1);
  digitalWrite(pS3,1);
  digitalWrite(pS4,1);  
}
