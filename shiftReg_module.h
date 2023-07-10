#include <stdint.h>
#include "planes.h"

#define clockPin 13
#define latchPin 12
#define dataPin 11

void displayPlane(plane planeToDisplay, int layerNum)
{
  digitalWrite(latchPin, LOW);
  uint8_t layerMask = 1 << layerNum;
  for(int i = 0; i < 4; i++)
  {
    shiftOut(dataPin, clockPin, MSBFIRST, planeToDisplay.matrix[i]);
  }
  shiftOut(dataPin, clockPin, MSBFIRST, layerMask);
  for(int i = 4; i < planeSize; i++)
  {
    shiftOut(dataPin, clockPin, MSBFIRST, planeToDisplay.matrix[i]);
  }
  digitalWrite(latchPin, HIGH);
}

void displayCube(cube cubeToDisplay)
{
  for(int i = 0; i < planeSize; i++)
  {
    displayPlane(cubeToDisplay.matrixPlane[i], i);
  }
}

void setupShiftReg()
 {
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
 }
