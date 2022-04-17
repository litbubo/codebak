int led1 = 5;          
int led2 = 6;
int brightness = 0;
int light = 20;

unsigned long time;
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  time = millis();
  if(time%2000==0&&time%4000!=0)
  {
    analogWrite(led1, brightness);
  }
  if(time%4000==0)
  {
    analogWrite(led1, light);
  }
  if(time%3000==0&&time%6000!=0)
  {
    analogWrite(led2, brightness);
  }
  if(time%6000==0)
  {
    analogWrite(led2, light);
  }
}
