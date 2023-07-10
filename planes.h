#ifndef PLANES_H
#define PLANES_H

#include <stdint.h>
#define planeSize 8

class plane
{
  public:
    plane(uint8_t one, uint8_t two, uint8_t three, uint8_t four, uint8_t five, uint8_t six, uint8_t seven, uint8_t eight)
    {
      matrix[0] = one;
      matrix[1] = two;
      matrix[2] = three;
      matrix[3] = four;
      matrix[4] = five;
      matrix[5] = six;
      matrix[6] = seven;
      matrix[7] = eight;
    }

    plane(uint8_t allTheSame)
    {
      matrix[planeSize] = {allTheSame};
    }

    plane()
    {
      matrix[planeSize] = {0};
    }
    
    uint8_t matrix[planeSize];
    
    plane operator+(const plane &m) 
    {
      plane result;
      for(int i = 0; i < planeSize; i++)
      {
        result.matrix[i] = matrix[i] | m.matrix[i];
      }
      return result;
    };
  private:

};

class cube
{
  public:
    cube(plane one, plane two, plane three, plane four, plane five, plane six, plane seven, plane eight)
    {
      matrixPlane[0] = one;
      matrixPlane[1] = two;
      matrixPlane[2] = three;
      matrixPlane[3] = four;
      matrixPlane[4] = five;
      matrixPlane[5] = six;
      matrixPlane[6] = seven;
      matrixPlane[7] = eight;
    }

    cube(plane allTheSame)
    {
      matrixPlane[planeSize] = {allTheSame};
    }

    cube()
    {
      matrixPlane[planeSize] = {plane(0)};
    }
    
    plane matrixPlane[planeSize];
    
    cube operator+(const cube &m) 
    {
      cube result;
      for(int i = 0; i < planeSize; i++)
      {
        result.matrixPlane[i] = matrixPlane[i] + m.matrixPlane[i];
      }
      return result;
    };
  private:

};

cube cubeInOut[4] = {
  cube(plane(0b11111111, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b11111111),
       plane(0b10000001, 0,0,0,0,0,0, 0b10000001),
       plane(0b10000001, 0,0,0,0,0,0, 0b10000001),
       plane(0b10000001, 0,0,0,0,0,0, 0b10000001),
       plane(0b10000001, 0,0,0,0,0,0, 0b10000001),
       plane(0b10000001, 0,0,0,0,0,0, 0b10000001),
       plane(0b10000001, 0,0,0,0,0,0, 0b10000001),
       plane(0b11111111, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b11111111)),

  cube(plane(0),
       plane(0, 0b01111110, 0b01000010, 0b01000010, 0b01000010, 0b01000010, 0b01111110, 0),
       plane(0, 0b01000010, 0, 0, 0, 0, 0b01000010, 0),
       plane(0, 0b01000010, 0, 0, 0, 0, 0b01000010, 0),
       plane(0, 0b01000010, 0, 0, 0, 0, 0b01000010, 0),
       plane(0, 0b01000010, 0, 0, 0, 0, 0b01000010, 0),
       plane(0, 0b01111110, 0b01000010, 0b01000010, 0b01000010, 0b01000010, 0b01111110, 0),
       plane(0)),

  cube(plane(0),
       plane(0),
       plane(0, 0, 0b00111100, 0b00100100, 0b00100100, 0b00111100, 0, 0),
       plane(0, 0, 0b00100100, 0, 0, 0b00100100, 0, 0),
       plane(0, 0, 0b00100100, 0, 0, 0b00100100, 0, 0),
       plane(0, 0, 0b00111100, 0b00100100, 0b00100100, 0b00111100, 0, 0),
       plane(0),
       plane(0)),

  cube(plane(0),
       plane(0),
       plane(0),
       plane(0, 0, 0, 0b00011000, 0b00011000, 0, 0, 0),
       plane(0, 0, 0, 0b00011000, 0b00011000, 0, 0, 0),
       plane(0),
       plane(0),
       plane(0)),
};

uint8_t cubeSmall[5][5] = {
  {0b11111, 0b10001, 0b10001, 0b10001, 0b11111},
  {0b10001, 0, 0, 0, 0b11111},
  {0b10001, 0, 0, 0, 0b11111},
  {0b10001, 0, 0, 0, 0b11111},
  {0b11111, 0b10001, 0b10001, 0b10001, 0b11111},
};

#endif
