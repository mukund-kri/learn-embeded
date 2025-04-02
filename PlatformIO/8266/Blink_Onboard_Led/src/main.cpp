#include <Arduino.h>

// Targeting internal LED
const int LED = D4;
const int DELAY = 1000;

void setup()
{
  // Initialize the LED pin as an output
  pinMode(LED, OUTPUT);
}

void loop()
{
  // Blink the LED
  digitalWrite(LED, HIGH);
  delay(DELAY);
  digitalWrite(LED, LOW);
  delay(DELAY);
}
