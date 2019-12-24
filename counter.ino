#include <Arduino.h>
#include "src/seven-segment.h"

#define S0_PIN 2
#define S1_PIN 3
#define S2_PIN 4
#define DIGIT_SELECT_PIN 5
#define ENABLE_PIN 12
#define COUNT_DELAY_PIN A2
#define SEGMENT_DELAY_PIN A1

SevenSegment display(S0_PIN, S1_PIN, S2_PIN, ENABLE_PIN);
int counter = 0;
int countDelay = 1000;
unsigned long lastTime = 0;
int countDirection = 1;

void setup() {
  pinMode(DIGIT_SELECT_PIN, OUTPUT);
}

void loop() {  
  int temp;  

  // set count delay and direction
  countDirection = 1;
  temp = map(analogRead(COUNT_DELAY_PIN), 0, 1023, -2900, 2900);
  countDelay = 3000 - abs(temp);
  if (temp < 0) countDirection = -1;

  // set segment delay
  temp = map(analogRead(SEGMENT_DELAY_PIN), 0, 1023, 0, 250);
  display.setSegmentDelay(temp);

  if (millis() - lastTime > countDelay) {    // wait for next count
    lastTime = millis();
    counter += countDirection;
    if (counter > 99) {
      counter = 0;
    }
    if (counter < 0) {
      counter = 99;
    }
  }

  // display 1's digit
  digitalWrite(DIGIT_SELECT_PIN, 0);
  display.show(counter%10);

  // display 10's digit
  digitalWrite(DIGIT_SELECT_PIN, 1);
  display.show(counter/10);
}