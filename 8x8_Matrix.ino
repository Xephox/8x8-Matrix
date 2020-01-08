#include "LedControl.h"
int DIN = 12;
int CS = 11;
int CLK = 10;

byte I[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
byte heart[]={B00000000,B01100110,B11111111,B11111111,B11111111,B01111110,B00111100,B00011000};
byte S[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
byte A[] = {  B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
byte M[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
LedControl lc=LedControl(DIN,CS,CLK,1);

void setup() {
lc.shutdown(0,false);
lc.setIntensity(0,8);
lc.clearDisplay(0);
}

void loop() {
printByte(I);
delay(1000);
printByte(heart);
delay(1000);
printByte(S);
delay(1000);
printByte(A);
delay(1000);
printByte(M);
delay(1000);
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
