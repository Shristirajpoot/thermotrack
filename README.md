TempSense Pro - IoT Temperature Monitoring System
TempSense Pro is an IoT-based temperature monitoring system built using the ESP32 microcontroller, DHT11 temperature sensor, and LCD display. This project continuously monitors ambient temperature and humidity, displays real-time data on an LCD, logs data to ThingSpeak, and sends temperature alerts via Telegram. When the temperature exceeds a specified threshold, the system activates an alert with both visual (LED) and sound (buzzer) notifications, along with a real-time message alert on Telegram.

Table of Contents 
- [Introduction](#introduction)
- [Features](#features)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Setup Guide](#setup-guide)
- [How to Use](#how-to-use)
- [Libraries Used](#libraries-used)
- [License](#license)

##Introduction
This project aims to create a remote temperature monitoring solution ideal for smart home or environmental monitoring applications. Using the ESP32's Wi-Fi capability, it streams real-time temperature and humidity data to the cloud (ThingSpeak) and sends alerts to users via a Telegram bot. The built-in LCD display also provides instant readings of temperature and humidity.

##Features
Real-Time Monitoring: Continuously measures ambient temperature and humidity.
LCD Display: Shows real-time data directly on an LCD for easy viewing.
Cloud Logging: Sends data to ThingSpeak for monitoring over time.
Telegram Alerts: Sends alerts to a Telegram bot when temperature exceeds the threshold.
Visual and Sound Alerts: Activates an LED and buzzer when the temperature goes above the defined limit.

##Components
ESP32: Main microcontroller that connects to the Wi-Fi network and sends data to ThingSpeak and Telegram.
DHT11 Temperature & Humidity Sensor: Reads temperature and humidity data.
LCD Display: Shows temperature and humidity values.
Buzzer: Sounds an alert if the temperature exceeds the threshold.
LED: Provides a visual alert when the temperature is above the limit.
ThingSpeak Account: For storing and visualizing temperature data.
Telegram Bot: For sending temperature and humidity alerts to the user.

##Circuit Diagram
Connection Details:

DHT11 Sensor:

VCC -> 3.3V on ESP32
Data -> GPIO pin on ESP32
GND -> GND on ESP32
LCD Display:

VCC -> VCC on ESP32
GND -> GND on ESP32
SCL -> SCL on ESP32
SDA -> SDA on ESP32
Buzzer and LED:

Buzzer and LED are connected to separate GPIO pins on the ESP32, with a shared GND connection.

##Setup Guide
1. ThingSpeak Setup
Create a ThingSpeak account.
Set up a new channel, and create fields for Temperature and Humidity.
Note down the Channel ID and Write API Key as you'll need to enter them in the code.
2. Telegram Bot Setup
Open Telegram and search for the BotFather (@BotFather).
Start a chat with BotFather and create a new bot by typing /newbot.
Follow the instructions to get your Bot Token.
Create a chat with your bot and note down your Chat ID (you can use a bot to retrieve your own Chat ID).
Enter the Bot Token and Chat ID in the code.
3. Wi-Fi Setup
Enter your Wi-Fi SSID and Password in the code.

##How to Use
Upload the Code:

Using the Arduino IDE, upload the provided code (main.cpp or TemperatureMonitor.ino) to the ESP32.
Run the System:

Once powered, the ESP32 will connect to Wi-Fi, retrieve time, and start reading temperature and humidity data from the DHT11 sensor.
The data will display on the LCD and automatically update on ThingSpeak.
Monitor Data Remotely:

You can check temperature and humidity data in real time on your ThingSpeak channel.
Receive Alerts:

If the temperature exceeds 34°C, the system triggers an alert:
The LED lights up.
The buzzer sounds an alert.
A message is sent to the Telegram bot.
Telegram Commands:

/Gettemp - Sends the current temperature reading.
/Gethumi - Sends the current humidity reading.

##Libraries Used
WiFi.h - Manages Wi-Fi connectivity.
ThingSpeak.h - Connects and sends data to the ThingSpeak server.
WiFiClientSecure.h - Provides secure client functionality for HTTPS connections.
UniversalTelegramBot.h - Integrates with Telegram to send and receive messages.
DHT.h - Manages data collection from the DHT11 sensor.
Installation: You can install these libraries directly from the Arduino IDE’s Library Manager.

##License
This project is licensed under the MIT License - see the LICENSE.md file for details.

