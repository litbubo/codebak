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
char a[11]="HELLO LIU ";        //共阳极

int t = 0;                      //计数，判定显示哪四个字母

void (*showLetter[10])();       //函数指针数组，定义十个函数

void setup()
{
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
  showLetter[0] = &ShowH;
  showLetter[1] = &ShowE;
  showLetter[2] = &ShowL;
  showLetter[3] = &ShowL;
  showLetter[4] = &ShowO;
  showLetter[5] = &Show_;
  showLetter[6] = &ShowL;
  showLetter[7] = &ShowI;
  showLetter[8] = &ShowU;
  showLetter[9] = &Show_;
}

void loop() {
  int time0 = 0;
  while(time0 < 1000)      //1s滚动一次
  {
  showLetter[(t+0)%10]();
  Show1();
  delay(5);
  showLetter[(t+1)%10]();
  Show2();
  delay(5);
  showLetter[(t+2)%10]();
  Show3();
  delay(5);
  showLetter[(t+3)%10]();
  Show4();
  delay(5);
  time0 += 20;
  }
  t++;
  if(t>9)
    t = 0;
}

void Show1()
{
  digitalWrite(pS1,1);
  digitalWrite(pS2,0);
  digitalWrite(pS3,0);
  digitalWrite(pS4,0);
}
void Show2()
{
  digitalWrite(pS1,0);
  digitalWrite(pS2,1);
  digitalWrite(pS3,0);
  digitalWrite(pS4,0);
}

void Show3()
{
  digitalWrite(pS1,0);
  digitalWrite(pS2,0);
  digitalWrite(pS3,1);
  digitalWrite(pS4,0);
}

void Show4()
{
  digitalWrite(pS1,0);
  digitalWrite(pS2,0);
  digitalWrite(pS3,0);
  digitalWrite(pS4,1);
}


void Show_()
{
  digitalWrite(pA,1);
  digitalWrite(pB,1);
  digitalWrite(pC,1);
  digitalWrite(pD,1);
  digitalWrite(pE,1);
  digitalWrite(pF,1);
  digitalWrite(pG,1);
  digitalWrite(pDP,1);
}

void ShowH()
{
  digitalWrite(pA,1);
  digitalWrite(pB,0);
  digitalWrite(pC,0);
  digitalWrite(pD,1);
  digitalWrite(pE,0);
  digitalWrite(pF,0);
  digitalWrite(pG,0);
  digitalWrite(pDP,1);
}

void ShowE()
{
  digitalWrite(pA,0);
  digitalWrite(pB,1);
  digitalWrite(pC,1);
  digitalWrite(pD,0);
  digitalWrite(pE,0);
  digitalWrite(pF,0);
  digitalWrite(pG,0);
  digitalWrite(pDP,1);
}

void ShowL()
{
  digitalWrite(pA,1);
  digitalWrite(pB,1);
  digitalWrite(pC,1);
  digitalWrite(pD,0);
  digitalWrite(pE,0);
  digitalWrite(pF,0);
  digitalWrite(pG,1);
  digitalWrite(pDP,1);
}

void ShowO()
{
  digitalWrite(pA,0);
  digitalWrite(pB,0);
  digitalWrite(pC,0);
  digitalWrite(pD,0);
  digitalWrite(pE,0);
  digitalWrite(pF,0);
  digitalWrite(pG,1);
  digitalWrite(pDP,1);
}

void ShowI()
{
  digitalWrite(pA,1);
  digitalWrite(pB,1);
  digitalWrite(pC,1);
  digitalWrite(pD,1);
  digitalWrite(pE,0);
  digitalWrite(pF,0);
  digitalWrite(pG,1);
  digitalWrite(pDP,1);
}

void ShowU()
{
  digitalWrite(pA,1);
  digitalWrite(pB,0);
  digitalWrite(pC,0);
  digitalWrite(pD,0);
  digitalWrite(pE,0);
  digitalWrite(pF,0);
  digitalWrite(pG,1);
  digitalWrite(pDP,1);
}
