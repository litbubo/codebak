#include <SPI.h>
 
const byte sprite[2][8] = {
     { 0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18 },  
     { 0x00, 0x00, 0x24, 0x7E, 0x7E, 0x3C, 0x18, 0x00 }     
};
 
const byte DECODEMODE = 0x09;
const byte INTENSITY = 0x0a;
const byte SCANLIMIT = 0x0b;
const byte SHUTDOWN = 0x0c;
const byte DISPLAYTEST = 0x0f;
 
void max7219(const byte reg, const byte data) {
   digitalWrite(SS, LOW);
   SPI.transfer(reg);
   SPI.transfer(data);
   digitalWrite(SS, HIGH);  
}
 
void setup() {
   SPI.begin();
    
   max7219(SCANLIMIT, 7);
   max7219(DECODEMODE, 0);
   max7219(INTENSITY, 2);
   max7219(DISPLAYTEST, 0);
   max7219(SHUTDOWN, 1);  
    
   for(byte i=0; i<8; i++) {
     max7219(i+1, 0);
   }
} 
 
void loop() {
   for(byte j=0; j<2; j++) {
     for(byte i=0; i<8; i++) {
       max7219(i+1, sprite[j][i]);
     }
   delay(200);
   }
}
