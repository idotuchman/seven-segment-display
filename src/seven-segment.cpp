#include "seven-segment.h"

SevenSegment::SevenSegment(int pin1, int pin2, int pin3, int enable) {
  s0 = pin1;
  s1 = pin2;
  s2 = pin3;
  en = enable;
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(en, OUTPUT);
  digitalWrite(en, HIGH);  // disable display
}

void SevenSegment::show(int value) {
  // iterate over all seven segments
  for (int seg = 0; seg < 7; seg++) {
    // check if segment should be turned on
    if ((values[value] >> (6 - seg)) & 1) {
      // turn on segment by extracting each select bit
      digitalWrite(s0, (seg >> 0) & 1);
      digitalWrite(s1, (seg >> 1) & 1);
      digitalWrite(s2, (seg >> 2) & 1); 
      digitalWrite(en, LOW);  // enable display
    }
    // delay on segment (even if off)
    delay(segmentDelay);
    digitalWrite(en, HIGH);  // disable display
  }
}

void SevenSegment::setSegmentDelay(int delayTime) {
  segmentDelay = 1;
  if (delayTime > 1) {
    segmentDelay = delayTime;
  }  
}