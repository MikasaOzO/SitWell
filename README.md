# Digital Weighing Scale with Dual Load Cells using HX711

This project demonstrates how to build a digital weighing scale that can read measurements from two independent load cells. It uses two HX711 ADC modules connected to an Arduino, allowing you to measure and display weight values from two separate load cells simultaneously.

## Features

- **Dual Load Cells**: Reads data from two separate load cells, each connected to its own HX711 module.
- **Calibration**: Allows setting a calibration factor for each load cell to ensure accurate readings.
- **Data Filtering**: Basic filtering logic (averaging multiple readings) to improve stability and reduce noise.
- **Independent Taring**: Each scale can be reset (tared) to zero independently at startup.

## Hardware Requirements

- **Arduino Board** (e.g., Arduino Uno)
- **2 x Load Cells** (each connected to its own HX711 amplifier/ADC module)
- **2 x HX711 Modules**
- **Jumper Wires** for connecting HX711 modules and load cells to the Arduino.
- **Known Weight for Calibration** (e.g., a known 100g weight to determine the calibration factor).

## Wiring

Each HX711 module has the following pins:
- VCC -> 5V Arduino
- GND -> GND Arduino
- DT  -> Arduino digital pin (DOUT or DOUT2 in code)
- SCK -> Arduino digital pin (SCK or SCK2 in code)

For each load cell, connect the E+, E-, A+, A- lines to the corresponding inputs on the HX711 module according to the module’s documentation.

Example pin mapping used in the code:
- First HX711:  
  - DOUT -> Arduino pin 3  
  - SCK  -> Arduino pin 2
- Second HX711:  
  - DOUT2 -> Arduino pin 5  
  - SCK2  -> Arduino pin 4

Adjust these pins as needed and update the code accordingly.

## Software Requirements

- **Arduino IDE**: To compile and upload the code to the Arduino.
- **HX711 Arduino Library**: Ensure you have the HX711 library installed. You can install it via the Arduino Library Manager (Sketch > Include Library > Manage Libraries...) or from GitHub.

## Installation

1. Clone or download this repository.
2. Place the Arduino `.ino` file in your Arduino sketch folder.
3. Open the `.ino` file with Arduino IDE.
4. Install the HX711 library if not already installed.
5. Connect your Arduino to your computer via USB.

## Usage

1. **Power On**: Connect your Arduino and both HX711 modules and load cells as described.
2. **Upload the Code**: In the Arduino IDE, select the correct board and COM port, then click "Upload".
3. **Serial Monitor**: Open the Serial Monitor at 9600 baud.  
   You will see output readings for both scales, for example:  
Weight (Scale 1): 0.00 g, Weight (Scale 2): 0.00 g
4. **Calibration**:  
- If readings are off, adjust the `calibration_factor` and `calibration_factor2` variables in the code.  
- To find a calibration factor, place a known weight on the load cell and adjust the factor until the displayed value matches the known weight.
5. **Filtering Negative Values**: The code includes logic to flip negative readings to positive and set small values to zero. You can modify or remove this logic based on your needs.

## Adjusting Calibration Factors

- Put a known weight on one load cell and note the reading.
- Calculate the calibration factor as `raw_reading / known_weight`.
- Update `calibration_factor` or `calibration_factor2` in the code and re-upload until the displayed weight matches the known weight.

## Future Improvements

- **Interactive Calibration**: Add serial commands to enter calibration mode and automatically calculate the calibration factor.
- **Advanced Filtering**: Implement median filtering or moving average filters to further smooth out readings.
- **EEPROM Storage**: Save calibration factors and other parameters in EEPROM so they persist after reset.

## Contributing

Feel free to submit pull requests or open issues if you have suggestions or want to add features.

## License

This project is provided under the [MIT License](LICENSE).

