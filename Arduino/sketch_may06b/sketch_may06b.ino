
int led1 =   6;       // led1 connected at pin 6
int led2 =   7;       // led1 connected at pin 7
int toggleLed = 5;     // push button controlled led connected at pin 5
int pushButton = 2;     // push butoon connected at pin 2 which is also interrupt pin
int ledState1 = LOW;   // to determine the states of led1 and led2
int ledState2 = LOW;
unsigned long previousMillis1 = 0;   //store last time LED1 was blinked
const long period1 = 1000;         // period at which led1 blinks in ms
unsigned long previousMillis2 = 0;   //store last time LED2 was blinked
const long period2 = 200;             // period at which led1 blinks in ms
int debouncePeriod = 20;             // debounce delay of 20ms
int debounceMillis = 0;             // similar to previousMillis
bool buttonPushed = false;     // interrupt routine button status
int ledChange = LOW;       // to track the led status last
int lastState = HIGH;     // to track last button state
void setup() {

pinMode(led1, OUTPUT);               // define pins as input or output

pinMode(led2, OUTPUT);

pinMode(toggleLed, OUTPUT);

pinMode(pushButton, INPUT);

attachInterrupt(digitalPinToInterrupt(pushButton), pushButton_ISR, CHANGE);   // use interrupt pin2

}

void pushButton_ISR()

{

buttonPushed = true;   // ISR should be as short as possible

}

void loop() {

unsigned long currentMillis = millis(); // store the current time

if (currentMillis - previousMillis1 >= period1) {
// check if 1000ms passed

previousMillis1 = currentMillis;   // save the last time you blinked the LED

if (ledState1 == LOW) {
        // if the LED is off turn it on and vice-versa

ledState1 = HIGH;   //change led state for next iteration

         
} else {

ledState1 = LOW;

         
}

digitalWrite(led1, ledState1);     //set LED with ledState to blink again

     
}

  
if (currentMillis - previousMillis2 >= period2) { // check if 200ms passed

previousMillis2 = currentMillis;   // save the last time you blinked the LED

if (ledState2 == LOW) { // if the LED is off turn it on and vice-versa

 ledState2 = HIGH;

         
} else {

ledState2 = LOW;

         
    
digitalWrite(led2, ledState2);//set LED with ledState to blink again

     
}


}
