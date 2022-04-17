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
char a[11] = "HELLOLIU";

int t = 0;

int (*p_arry[11])() = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
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
  p_arry[0] = &Show1;
  p_arry[1] = &Show2;
  p_arry[2] = &Show3;
  p_arry[3] = &Show4;
  p_arry[4] = &Show5;
  p_arry[5] = &Show6;
  p_arry[6] = &Show7;
  p_arry[7] = &Show8;
  p_arry[8] = &Show9;
  p_arry[9] = &Show10;
  p_arry[10] = &Show11;

}

void loop()
{

  for (int i = 0; i < 1000; i+=20)
  {
    p_arry[t++ % 10]();
    Showa();
    delay(5);
    p_arry[(t++) % 10]();
    Showb();
    delay(5);
    p_arry[(t++) % 10]();
    Showc();
    delay(5);
    p_arry[(t++) % 10]();
    Showd();
    delay(5);

  }
  
  t++;
}
void Show1()
{
  digitalWrite(pA, 1);
  digitalWrite(pB, 1);
  digitalWrite(pC, 1);
  digitalWrite(pD, 1);
  digitalWrite(pE, 1);
  digitalWrite(pF, 1);
  digitalWrite(pG, 1);
  digitalWrite(pDP, 1);
}

void Show2()
{
  digitalWrite(pA, 1);
  digitalWrite(pB, 0);
  digitalWrite(pC, 0);
  digitalWrite(pD, 1);
  digitalWrite(pE, 0);
  digitalWrite(pF, 0);
  digitalWrite(pG, 0);
  digitalWrite(pDP, 1);
}

void Show3()
{
  digitalWrite(pA, 0);
  digitalWrite(pB, 1);
  digitalWrite(pC, 1);
  digitalWrite(pD, 0);
  digitalWrite(pE, 0);
  digitalWrite(pF, 0);
  digitalWrite(pG, 0);
  digitalWrite(pDP, 1);
}

void Show4()
{
  digitalWrite(pA, 1);
  digitalWrite(pB, 1);
  digitalWrite(pC, 1);
  digitalWrite(pD, 0);
  digitalWrite(pE, 0);
  digitalWrite(pF, 0);
  digitalWrite(pG, 1);
  digitalWrite(pDP, 1);
}
void Show5()
{
  digitalWrite(pA, 1);
  digitalWrite(pB, 1);
  digitalWrite(pC, 1);
  digitalWrite(pD, 0);
  digitalWrite(pE, 0);
  digitalWrite(pF, 0);
  digitalWrite(pG, 1);
  digitalWrite(pDP, 1);
}
void Show6()
{
  digitalWrite(pA, 0);
  digitalWrite(pB, 0);
  digitalWrite(pC, 0);
  digitalWrite(pD, 0);
  digitalWrite(pE, 0);
  digitalWrite(pF, 0);
  digitalWrite(pG, 1);
  digitalWrite(pDP, 1);
}

void Show7()
{
  digitalWrite(pA, 1);
  digitalWrite(pB, 1);
  digitalWrite(pC, 1);
  digitalWrite(pD, 1);
  digitalWrite(pE, 1);
  digitalWrite(pF, 1);
  digitalWrite(pG, 1);
  digitalWrite(pDP, 1);
}
void Show8()
{
  digitalWrite(pA, 1);
  digitalWrite(pB, 1);
  digitalWrite(pC, 1);
  digitalWrite(pD, 0);
  digitalWrite(pE, 0);
  digitalWrite(pF, 0);
  digitalWrite(pG, 1);
  digitalWrite(pDP, 1);
}

void Show9()
{
  digitalWrite(pA, 1);
  digitalWrite(pB, 0);
  digitalWrite(pC, 0);
  digitalWrite(pD, 1);
  digitalWrite(pE, 1);
  digitalWrite(pF, 1);
  digitalWrite(pG, 1);
  digitalWrite(pDP, 1);
}
void Show10()
{
  digitalWrite(pA, 1);
  digitalWrite(pB, 0);
  digitalWrite(pC, 0);
  digitalWrite(pD, 0);
  digitalWrite(pE, 0);
  digitalWrite(pF, 0);
  digitalWrite(pG, 1);
  digitalWrite(pDP, 1);
}
void Show11()
{
  digitalWrite(pA, 1);
  digitalWrite(pB, 1);
  digitalWrite(pC, 1);
  digitalWrite(pD, 1);
  digitalWrite(pE, 1);
  digitalWrite(pF, 1);
  digitalWrite(pG, 1);
  digitalWrite(pDP, 1);
}
void Showa()
{
  digitalWrite(pS1, 1);
  digitalWrite(pS2, 0);
  digitalWrite(pS3, 0);
  digitalWrite(pS4, 0);
}
void Showb()
{
  digitalWrite(pS1, 0);
  digitalWrite(pS2, 1);
  digitalWrite(pS3, 0);
  digitalWrite(pS4, 0);
}

void Showc()
{
  digitalWrite(pS1, 0);
  digitalWrite(pS2, 0);
  digitalWrite(pS3, 1);
  digitalWrite(pS4, 0);
}

void Showd()
{
  digitalWrite(pS1, 0);
  digitalWrite(pS2, 0);
  digitalWrite(pS3, 0);
  digitalWrite(pS4, 1);
}
