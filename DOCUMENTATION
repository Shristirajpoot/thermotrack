# Documentation Folder (docs)

## Overview

This folder contains all necessary documentation for the temperature monitoring system, including circuit diagrams, detailed explanations of each component, code usage, and additional screenshots of the system in action.

---

## 1. Circuit Diagram
   - **Diagram**: Include a clear image or diagram of the connections.
   - **Components List**:
     - ESP32 microcontroller
     - DHT11 temperature and humidity sensor
     - LCD display
     - Buzzer
     - LED
     - USB cable (for connecting ESP32 to the laptop)

---

## 2. Component Details and Circuit Explanation

   - **DHT11 Sensor**: Measures temperature and humidity, with data sent to ESP32. Connected via VCC, GND, and DATA pins to ESP32.
   - **LCD Display**: Shows temperature and humidity data. Connected via VCC, GND, SCL, and SDA to ESP32 for communication.
   - **Buzzer and LED**: Both connected to ESP32 GPIO for alerts. Common GND with ESP32, and LED is controlled by GPIO 12.
   - **ESP32 Wi-Fi Connection**: Transmits data to ThingSpeak and communicates with Telegram bot for live monitoring.
   
---

## 3. Code Explanation and Data Processing

   - **Code Structure**:
     - `setup()`: Configures Wi-Fi, initializes components, connects to ThingSpeak, and sets up Telegram bot.
     - `loop()`: Reads data from the DHT11 sensor, processes it, and performs the following:
       - Checks temperature against threshold (34°C) to activate buzzer and LED alert.
       - Sends data to ThingSpeak at specified intervals.
       - Responds to Telegram bot commands (`/Gettemp` for temperature, `/Gethumi` for humidity).

---

## 4. How Alerts Are Handled

   - **ThingSpeak Alerts**: Temperature and humidity data are sent to ThingSpeak, where users can view real-time graphs and logs.
   - **Telegram Bot Alerts**:
     - Sends alert to specified Telegram user if temperature exceeds threshold.
     - Responds to commands for on-demand temperature and humidity readings.

---

## 5. Screenshots

   - Include images of:
     - The hardware setup with all components connected.
     - The ThingSpeak dashboard displaying data in real-time.
     - Telegram bot screenshots showing response to commands and alerts.

---

## 6. Usage Instructions

   1. **Setup Wi-Fi**: Edit code with Wi-Fi credentials.
   2. **ThingSpeak**: Register and set up a channel on ThingSpeak; add the channel number and API key in code.
   3. **Telegram Bot**: Register a bot on Telegram, then add bot token and chat ID to the code.
   4. **Run**: Upload code to ESP32, and use serial monitor to observe debug messages.

---

## 7. Additional Notes

   - Ensure ESP32 stays connected to Wi-Fi for uninterrupted monitoring.
   - Modify temperature threshold in code to suit different environments.
   - Always power off components before making changes to wiring.

--- 

This documentation should help others set up, use, and understand the temperature monitoring system.
