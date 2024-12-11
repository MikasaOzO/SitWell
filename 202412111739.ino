/*
 *  Digital Weighing Scale with Load Cell
 *  Compatible with Updated HX711 Library
 */

#include "HX711.h"  // You must have this library in your Arduino library folder

// Wiring definition for the first Load Cell
#define DOUT  3
#define SCK   2

// Wiring definition for the second Load Cell (adjust according to your setup)
#define DOUT2 5
#define SCK2  4

HX711 scale;    // HX711 instance for the first load cell
HX711 scale2;   // HX711 instance for the second load cell

float calibration_factor = -22.3;    // Calibration factor for the first load cell
float calibration_factor2 = 30;   // Calibration factor for the second load cell
float units;
float units2;  // Stores the measurement from the second load cell

void setup() {
  Serial.begin(9600);

  // Initialize the first load cell module
  scale.begin(DOUT, SCK); // Use begin() method to initialize with given pins
  scale.set_scale(calibration_factor); // Set the calibration factor
  scale.tare(); // Reset the scale to zero
  
  // Initialize the second load cell module
  scale2.begin(DOUT2, SCK2);
  scale2.set_scale(calibration_factor2);
  scale2.tare(); // Reset the second scale to zero
}

void loop() {
  // Get the weight reading from the first scale
  units = scale.get_units(5); // Average of 5 readings for stability
  if (units < 0) {
    units = -units; // Prevent negative weights
  }
  if (units < 100) {
    units = 0; // Prevent negative weights
  }

  // Get the weight reading from the second scale
  units2 = scale2.get_units(5);
  if (units2 < 0) {
    units2 = -units2; // Prevent negative weights
  }
  if (units2 < 100) {
    units2 = 0; // Prevent negative weights
  }

  // Print both weights to the Serial Monitor
  Serial.print("Weight (Scale 1): ");
  Serial.print(units, 2); // Display weight with 2 decimal places
  Serial.print(" g,   Weight (Scale 2): ");
  Serial.print(units2, 2);
  Serial.println(" g");

  delay(1000); // Slight delay for stability
}
