//#include "shiftReg_module.h"

#define clockPin 13
#define latchPin 12
#define dataPin 11

void setup()
{
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT); 
  digitalWrite(latchPin, LOW);
  uint8_t display = 0b11111111;
  for(int i = 0; i < 9; i++)
  {
    shiftOut(dataPin, clockPin, MSBFIRST, display);
  }
  digitalWrite(latchPin, HIGH);
}

void loop ()
{

}