# IoT-Based Smart Seed Sowing Robot

## Overview
The Smart Seed Sowing Robot is an IoT-enabled agricultural automation system developed using ESP8266 NodeMCU, Blynk, DC motors, and a servo motor. The robot can be controlled wirelessly through a smartphone and is capable of automated seed dispensing.

## Features
- Wireless control using Blynk mobile application
- Forward, backward, left, and right movement
- Automated seed dispensing using servo motor
- WiFi-based communication
- Low-cost agricultural automation solution

## Hardware Components
- ESP8266 NodeMCU
- L298N Motor Driver
- DC Motors
- Servo Motor (SG90)
- Robot Chassis
- Battery Pack
- Jumper Wires

## Software Used
- Arduino IDE
- Blynk IoT Platform

## Pin Configuration

| NodeMCU Pin | Function |
|------------|----------|
| D5 | ENA |
| D1 | IN1 |
| D2 | IN2 |
| D3 | IN3 |
| D4 | IN4 |
| D0 | ENB |
| D7/D8 | Servo Signal |

## Blynk Virtual Pins

| Function | Virtual Pin |
|----------|------------|
| Forward | V0 |
| Backward | V1 |
| Left | V2 |
| Right | V3 |
| Seed Drop | V6 |

## Working
The NodeMCU receives commands from the Blynk mobile application through WiFi. Based on user input, the robot moves in the desired direction and dispenses seeds using a servo-controlled mechanism.

## Technologies Used
- IoT
- ESP8266
- Embedded C
- Arduino IDE
- Blynk
- WiFi Communication

## Future Enhancements
- Obstacle Detection
- GPS Navigation
- Soil Moisture Monitoring
- Solar Power Integration
- Autonomous Operation

## Author
Abhijith T A
Bachelor of Computer Applications (AIML)
