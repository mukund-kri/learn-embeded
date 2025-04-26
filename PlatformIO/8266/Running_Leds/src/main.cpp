#include <Arduino.h>

// List the GPIO pins connected to the LEDs
const int ledPins[] = {D5, D6, D7, D8};
const int noOfLeds = 4;
const int ledOnTime = 500; // Time to keep the LED on in milliseconds

void setup()
{
  // Set the GPIO pins as outputs and set the initial state to LOW
  for (int i = 0; i < noOfLeds; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop()
{

  // Turn on and of the LEDs in turn
  for (int i = 0; i < noOfLeds; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    delay(ledOnTime); // Keep the LED on for 500 milliseconds
    digitalWrite(ledPins[i], LOW);
  }
}
