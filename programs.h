
#include "planes.h"
#include "shiftReg_module.h"

#define numOfPlanes 8

int counter = 0;


void resetCounter()
{
  counter = 0;
}

void programAllOn()
{
  for(int i = 0; i < numOfPlanes; i++)
  {
    displayPlane(plane(255, 255, 255, 255, 255, 255, 255, 255), i);
  }
}

void programAllOff()
{
  for(int i = 0; i < numOfPlanes; i++)
  {
  displayPlane(plane(0,0,0,0,0,0,0,0), i);
  }
}