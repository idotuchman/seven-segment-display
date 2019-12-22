#include <Arduino.h>
#ifndef SEVEN_SEGMENT_H
#define SEVEN_SEGMENT_H

class SevenSegment 
{
  public:
    SevenSegment(int s0_pin, int s1_pin, int s2_pin, int enable_pin);
    void show(int value);
    void setSegmentDelay(int delayTime);

  private:
    int s0;
    int s1;
    int s2;
    int en;
    int segmentDelay = 2;
        
// Segments layout:
//      a
//  f       b
//      g
//  e       c
//      d
    int values[10] = {
    // abcdefg
      B1111110,   // 0
      B0110000,   // 1
      B1101101,   // 2
      B1111001,   // 3
      B0110011,   // 4
      B1011011,   // 5
      B1011111,   // 6
      B1110000,   // 7
      B1111111,   // 8
      B1111011    // 9
    };
};

#endif