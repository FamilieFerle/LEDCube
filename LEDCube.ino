#include "programs.h"

#define clockPin 13
#define latchPin 12
#define dataPin 11

uint64_t milliCounter = 0;

void setup()
{
  setupShiftReg();
  while(millis() - milliCounter < 5000)
  {
    programAllOn();
  }
}

void loop ()
{
  milliCounter = millis();
  while(programMovingPlaneUpDown(millis() - milliCounter, 2))  {}
  milliCounter = millis();
  while(programMovingPlaneLeftRight(millis() - milliCounter, 2))  {}
  milliCounter = millis();
  while(programMovingPlaneBackForth(millis() - milliCounter, 2))  {}
}