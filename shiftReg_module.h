#include "matrixes.h"

#define clockPin 13
#define latchPin 12
#define dataPin 11

matrixes matrixToDisplay = matrix_uhr;
int64_t millisCounter = 0;
bool showNames = true;
int64_t millisNamesCounter = millis();

void displayMatrix(matrixes matrix)
{
  for(int i = 0; i < matrixSize; i++)
  {
    int16_t rowMask = 1 << (6 + i);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, rowMask >> 8);
    shiftOut(dataPin, clockPin, MSBFIRST, rowMask);
    shiftOut(dataPin, clockPin, LSBFIRST, ~(matrix.matrix[i]));
    shiftOut(dataPin, clockPin, LSBFIRST, ~(matrix.matrix[i]>>8));
    digitalWrite(latchPin, HIGH);
  }
}

void setupShiftReg()
 {
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  displayMatrix(matrix_5minutes[0]);
 }

void shutOffLeds()
{
  displayMatrix(matrix_5minutes[0]);
}

void runShiftReg(RtcDateTime nowIs)
{
  int hourIdx, minIdx, min5Idx;
  if(showNames)
  {
    matrixToDisplay = matrix_names;
    if(millis() - millisNamesCounter > 10000)
    {
      showNames = false;
    }
  }
  else
  {
    if(millis() - millisCounter > 10000)//only every ten seconds
    {
      millisCounter = millis();
      hourIdx = (nowIs.Minute() < 25 ? nowIs.Hour() : nowIs.Hour() + 1) % 12;
      hourIdx = hourIdx == 12 ? 0 : hourIdx;
      minIdx = nowIs.Minute() / 5;
      min5Idx = nowIs.Minute() % 5;
      matrixToDisplay = matrix_esIst + matrix_hours[hourIdx] + matrix_minutes[minIdx] + matrix_5minutes[min5Idx];
      for(int i = 0; i < matrixSize; i++)
      {
      }
    }
  }
  
  displayMatrix(matrixToDisplay);
}