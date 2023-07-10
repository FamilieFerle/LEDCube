#include <stdint.h>

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

bool programMovingPlaneUpDown(uint64_t msTime, int count)
{
  int layerOn = msTime / 300;
  bool doItAgain = lay
  layerOn = layerOn / 16;
  layerOn = layerOn > 7 ? 15 - layerOn : layerOn;

  displayPlane(plane(255, 255, 255, 255, 255, 255, 255, 255), layerOn);
  for(int i = 1; i < numOfPlanes; i++)
  {
    if(i != layerOn) 
      displayPlane(plane(0,0,0,0,0,0,0,0), i);
  }
  return msTime
}

bool programMovingPlaneLeftRight(uint64_t msTime, int count)
{
  int layerOn = msTime / 300;
  layerOn = layerOn / 16;
  layerOn = layerOn > 7 ? 15 - layerOn : layerOn;
  uint8_t mask = 1 << layerOn;

  displayPlane(plane(255, 255, 255, 255, 255, 255, 255, 255), layerOn);
  for(int i = 1; i < numOfPlanes; i++)
  {
    if(i != layerOn) 
      displayPlane(plane(0,0,0,0,0,0,0,0), i);
  }
}

bool programMovingPlaneBackForth(uint64_t msTime, int count)
{
  int layerOn = msTime / 300;
  layerOn = layerOn / 16;
  layerOn = layerOn > 7 ? 15 - layerOn : layerOn;

  displayPlane(plane(255, 255, 255, 255, 255, 255, 255, 255), layerOn);
  for(int i = 1; i < numOfPlanes; i++)
  {
    if(i != layerOn) 
      displayPlane(plane(0,0,0,0,0,0,0,0), i);
  }
}