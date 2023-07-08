#include <stdint.h>
const int planeSize = 8;

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

static plane fullOn = plane(0b11111111, 0b11111111, 0b11111111, 0b11111111,
                            0b11111111, 0b11111111, 0b11111111, 0b11111111);