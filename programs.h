#include <stdint.h>

#include "planes.h"
#include "shiftReg_module.h"

#define numOfPlanes 8

int counter = 0;


int getLayer(uint64_t time, int cycleNum, int speed)
{
  int layerOn = (time / speed) % cycleNum;
  return (layerOn >= cycleNum/2) ? cycleNum - 1 - layerOn : layerOn;
}

void programAllOn()
{
  displayCube(cube(plane(255)));
}

void programAllOff()
{
  displayCube(cube(plane(0)));
}

bool programMovingPlaneUpDown(uint64_t msTime, int count)
{
  const int cycleNmr = 16;
  const int movingSpeed = 300;
  int layerOn = getLayer(msTime, cycleNmr, movingSpeed);

  cube cubeToDisplay = cube(plane(0));
  cubeToDisplay.matrixPlane[layerOn] = plane(255);
  displayCube(cubeToDisplay);
  return (msTime / movingSpeed) / cycleNmr < count;
}

bool programMovingPlaneLeftRight(uint64_t msTime, int count)
{
  const int cycleNmr = 16;
  const int movingSpeed = 300;
  int layerOn = getLayer(msTime, cycleNmr, movingSpeed);
  
  int mask = 1 << layerOn;
  displayCube(cube(plane(mask)));
  return (msTime / movingSpeed) / cycleNmr < count;
}

bool programMovingPlaneBackForth(uint64_t msTime, int count)
{
  const int cycleNmr = 16;
  const int movingSpeed = 300;
  int layerOn = getLayer(msTime, cycleNmr, movingSpeed);

  plane display = plane(0);
  display.matrix[layerOn] = 255;
  displayCube(cube(display));
  return (msTime / movingSpeed) / cycleNmr < count;
}

bool programMovingCubeOutIn(uint64_t msTime, int count)
{
  const int cycleNmr = 8;
  const int movingSpeed = 500;
  int layerOn = getLayer(msTime, cycleNmr, movingSpeed);

  displayCube(cubeInOut[layerOn]);
  return (msTime / movingSpeed) / cycleNmr < count;
}