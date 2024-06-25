# Rocket Ground Station Arduino Code

![Logo](logo.png)

This repository contains a sample code for the [mertkaplandar/rocket-ground-station-app](https://github.com/mertkaplandar/rocket-ground-station-app) interface to work. This code is developed to receive data using a LoRa module and write these data to the serial port screen in JSON format.

You can view this text in Turkish by clicking [here](README_TR.md).

## Notes
For the [mertkaplandar/rocket-ground-station-app](https://github.com/mertkaplandar/rocket-ground-station-app) application to work, the DataPack structure in the code must be used without any changes. Unused data should be left empty and still written to the serial port screen in JSON format.

## Features

- Data reception using the LoRa module.
- Writing received data to the serial port screen in JSON format.

## Sample Serial Port Output
`{"name":"Rocket","packageNumber":1,"latitude":41.0048519,"longitude":28.9709240,"speed":227,"pressure":100801.1,"altitude":0.10569,"temperature": 26.03,"pitch":0,"roll":-5.6875,"yaw":-1.0625,"pyroTrigger":false,"flightStatus":true}`

Data should be written to the serial port screen instantly in this way. For example, if `pyrotrigger` data will not be used, the data should be kept in json, but its content should be left blank.

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

