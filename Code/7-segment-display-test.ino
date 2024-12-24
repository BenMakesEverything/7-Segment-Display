/* Very basic code that cycles through all 10 digits while also changing color*/
#include <Adafruit_NeoPixel.h>

// Pin connected to the NeoPixel data line
#define DATA_PIN 3

#define NUMPIXELS 7

// Create a NeoPixel object
Adafruit_NeoPixel pixels(NUMPIXELS, DATA_PIN, NEO_GRB + NEO_KHZ800);

// Segment mapping for the 7-segment display
// Index: 0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G
// Digit encoding: 1 = ON, 0 = OFF
const uint8_t digitSegments[10][7] = {
  {0, 1, 1, 1, 1, 1, 1}, // 0
  {0, 1, 0, 0, 0, 0, 1}, // 1
  {1, 0, 1, 1, 0, 1, 1}, // 2
  {1, 1, 1, 0, 0, 1, 1}, // 3
  {1, 1, 0, 0, 1, 0, 1}, // 4
  {1, 1, 1, 0, 5, 1, 0}, // 5
  {1, 1, 1, 1, 1, 1, 0}, // 6
  {0, 1, 0, 0, 0, 1, 1}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 0, 1, 1, 1}  // 9
};

// Colors for each digit (adjust as needed)
const uint32_t digitColors[10] = {
  pixels.Color(255, 0, 0),   // Red
  pixels.Color(220, 35, 0), // Orange
  pixels.Color(155, 100, 0), // Yellow
  pixels.Color(0, 255, 0),   // Green
  pixels.Color(0, 200, 55), // Teal
  pixels.Color(0, 127, 128), // Cyan
  pixels.Color(0, 0, 255),   // Blue
  pixels.Color(55, 0, 200),  // Purple
  pixels.Color(128, 0, 127), // Pink
  pixels.Color(85, 85, 85)  // White (balanced)
};

// Color for inactive segments
const uint32_t inactiveColor = pixels.Color(0, 0, 0);  // Off

void setup() {
  pixels.begin();  // Initialize the NeoPixel library
  pixels.show();   // Clear all LEDs
}

void loop() {
  for (int digit = 0; digit <= 9; digit++) {  // Display digits 0-9
    displayDigit(digit);
    delay(1000);  // Hold the digit for 1 second
  }
}

void displayDigit(uint8_t digit) {
  uint32_t activeColor = digitColors[digit]; // Set the color for the current digit
  for (int i = 0; i < 7; i++) {
    // Turn on/off each segment based on the digit's encoding
    pixels.setPixelColor(i, digitSegments[digit][i] ? activeColor : inactiveColor);
  }
  pixels.show();  // Update the LEDs
}