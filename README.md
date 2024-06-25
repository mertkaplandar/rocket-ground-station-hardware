# Rocket Ground Station Arduino Code

This repository contains a sample code for the [mertkaplandar/rocket-ground-station-app](https://github.com/mertkaplandar/rocket-ground-station-app) interface to work. This code is developed to receive data using a LoRa module and write these data to the serial port screen in JSON format.

You can view this text in Turkish by clicking [here](README.md).

## Notes
For the [mertkaplandar/rocket-ground-station-app](https://github.com/mertkaplandar/rocket-ground-station-app) application to work, the DataPack structure in the code must be used without any changes. Unused data should be left empty and still written to the serial port screen in JSON format.

## Features

- Data reception using the LoRa module.
- Writing received data to the serial port screen in JSON format.

## Requirements

- Arduino
- LoRa E32 module
- ArduinoJson library
- SoftwareSerial library

## Installation

1. Download and install the Arduino IDE.
2. Connect your Arduino board to your computer.
3. Open the Arduino IDE and load this project.
4. Install the required libraries:
   - `LoRa_E32`
   - `SoftwareSerial`
   - `ArduinoJson`

## Usage

1. Set the necessary pins for `mySerial`.
2. Configure your LoRa module and update the `LORA_ADDR` and `LORA_CH` parameters.
3. Upload the code to your Arduino board.
4. Open the serial monitor and see the data written in JSON format.

