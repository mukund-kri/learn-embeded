#include <Arduino.h>

// gpio to the shift register
const int clearPin = D5;
const int serialData = D6;
const int shiftClock = D7;
const int latchClock = D8;

// time delay for next clock pulse
const int delayTime = 1000; // in microseconds

void setup()
{
  // Declare the pins as output
  pinMode(clearPin, OUTPUT);
  pinMode(serialData, OUTPUT);
  pinMode(shiftClock, OUTPUT);
  pinMode(latchClock, OUTPUT);

  digitalWrite(clearPin, LOW);  // Activate the clear pin. This clears the shift register
  delay(1);                     // Wait for 1ms
  digitalWrite(clearPin, HIGH); // Deactivate the clear pin
}

void loop()
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(latchClock, LOW); // Lock in the output so that LEDs stat the same

    int data = 1 << i;                                // Data to be shifted out
    shiftOut(serialData, shiftClock, MSBFIRST, data); // Shift out the data to the shift register
    digitalWrite(latchClock, HIGH);                   // Latch the data to the output pins
    delay(delayTime);                                 // Wait for the next clock pulse
  }
}
