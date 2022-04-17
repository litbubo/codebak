int LED = 6;
int condition_l = 0;
int condition_b = 0;
unsigned long time_LED = 0;
unsigned long time_BUILTIN = 0;
const long period_LED = 3000;
const long period_BUILTIN = 200;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED, OUTPUT);
}
void loop() {
  unsigned long time_total = millis();
  if (time_total - time_LED >= period_LED) {
    time_LED = time_total;
    condition_l = 1 - condition_l;
    digitalWrite(LED, condition_l);
  }
  if (time_total - time_BUILTIN >= period_BUILTIN) {
    time_BUILTIN = time_total;
    condition_b = 1 - condition_b;
    digitalWrite(LED_BUILTIN, condition_b);
  }
}
