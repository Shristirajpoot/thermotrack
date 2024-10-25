# Temperature Monitoring System Connections

## Circuit Connections

1. **DHT11 Sensor**:
   - The **VCC** pin of the DHT11 is connected to the **3.3V** pin of the ESP32. This provides the necessary power for the sensor to operate.
   - The **GND** pin of the DHT11 is connected to the **GND** of the ESP32, establishing a common ground for the circuit.
   - The **DATA** pin of the DHT11 is connected to a designated GPIO pin (GPIO 14) on the ESP32 (defined as `DHTPIN` in the code) for reading temperature and humidity data.

2. **LCD Display**:
   - The **VCC** and **GND** pins of the LCD are connected to the **3.3V** and **GND** of the ESP32, respectively, ensuring the LCD has the correct power supply.
   - The **SCL** (Serial Clock) and **SDA** (Serial Data) lines of the LCD are connected to the corresponding pins on the ESP32, allowing for data communication between the ESP32 and the LCD.

3. **Buzzer and LED**:
   - The buzzer and the LED are connected to a common ground, ensuring that they can operate based on the ESP32's GPIO output signals.
   - The LED is connected to GPIO pin 12 (defined as `LED_PIN` in the code), which will be used to indicate high temperature alerts.

4. **USB Connection**:
   - A USB connection is established between the ESP32 and a laptop for programming the ESP32 and monitoring serial output during development.

5. **Connectivity**:
   - The ESP32 connects to Wi-Fi for real-time data transmission to ThingSpeak and communication with the Telegram bot. The Wi-Fi credentials are provided in the code.

## Functionality Overview

The system continuously monitors the temperature and humidity levels. If the temperature exceeds a defined threshold (34°C in this case), the LED lights up, and an alert message is sent via the Telegram bot. Data is also logged and visualized on ThingSpeak.

---

# CONFIGURATION.md

## Configuration Instructions

### Wi-Fi Credentials
- Update the following lines in the code with your Wi-Fi network details:
  ```cpp
  const char* ssid = "YOUR_SSID"; // Replace with your Wi-Fi SSID
  const char* password = "YOUR_PASSWORD"; // Replace with your Wi-Fi password

### ThingSpeak Setup
1.Create an account on ThingSpeak.
2.Create a new channel and note the Channel ID and Write API Key.
.3Update the following lines in the code with your ThingSpeak channel details:

unsigned long myChannelNumber = YOUR_CHANNEL_ID; // Replace with your ThingSpeak Channel ID
const char * myWriteAPIKey = "YOUR_WRITE_API_KEY"; // Replace with your Write API Key

### Telegram Bot Setup
1.Create a new bot on Telegram using BotFather.
2.Note the Token provided by BotFather and update the following line in the code:
#define BOT_TOKEN "YOUR_BOT_TOKEN" // Replace with your Telegram bot token
3.Replace the chat_id with your chat ID, which can be obtained by sending a message to your bot and checking the updates.

Ensure that all connections are securely made, and the necessary libraries are included in your Arduino IDE for compilation.

Feel free to modify any sections to better match your project specifics or preferences!
