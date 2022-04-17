int LED = 11;
int brightness = 0;
int button_imp = 2;
int button_reduce = 1;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(button_imp, INPUT_PULLUP);
  pinMode(button_reduce, INPUT_PULLUP);
}

void loop() {
  analogWrite(LED, brightness);
  int control_imp = digitalRead(button_imp);
  int control_reduce = digitalRead(button_reduce);
  if (control_imp == 0 && brightness <= 200)
    brightness++;
  if (control_reduce == 0 && brightness >= 1)
    brightness--;
  delay(20);
}
