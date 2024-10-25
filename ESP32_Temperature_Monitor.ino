#include <WiFi.h>  // Include the Wi-Fi library for ESP32
#include "ThingSpeak.h"  // Include the ThingSpeak library for data handling
#include <WiFiClientSecure.h>  // Include secure Wi-Fi client for secure communication
#include <UniversalTelegramBot.h>  // Include the library for Telegram bot integration
#include <DHT.h>  // Include the library for DHT temperature and humidity sensor

// Define the pin numbers for LED and DHT sensor
#define LED_PIN 12  // LED pin
#define DHTPIN 14  // DHT sensor pin
#define DHTTYPE DHT11  // Define the type of DHT sensor (DHT11)
DHT dht(DHTPIN, DHTTYPE);  // Create an instance of the DHT class

// Wi-Fi credentials
const char* ssid = "IOT";  // Wi-Fi SSID
const char* password = "1234567890";  // Wi-Fi password

WiFiClient  client;  // Create a Wi-Fi client
unsigned long myChannelNumber = 2631017;  // ThingSpeak channel number
const char * myWriteAPIKey = "EM0X5VLI8ZLDHD0F";  // API key for writing data to ThingSpeak

// Define the Telegram bot token
const char* BOT_TOKEN = std::getenv("BOT_TOKEN");
String chid = "-4550456385";  // Chat ID for Telegram

WiFiClientSecure secured_client;  // Create a secure Wi-Fi client
UniversalTelegramBot bot(BOT_TOKEN, secured_client);  // Create an instance of the Telegram bot

const unsigned long BOT_MTBS = 1000;  // Minimum time between bot messages (milliseconds)
unsigned long bot_lasttime;  // Store the last time a bot message was sent
unsigned long lastTime = 0;  // Store the last time ThingSpeak data was sent
unsigned long timerDelay = 30000;  // Delay for sending data to ThingSpeak (milliseconds)

// Strings to hold messages and chat IDs
String text;  
String chat_id;  
String message;  
String message1;

// Read initial humidity and temperature values
float h = dht.readHumidity();  // Read humidity from DHT sensor
float t = dht.readTemperature();  // Read temperature from DHT sensor

// Function to handle incoming messages from Telegram
void handleNewMessages(int numNewMessages) {
  Serial.print("handleNewMessages ");  // Print number of new messages
  Serial.println(numNewMessages);  // Print the count of new messages
  for (int i = 0; i < numNewMessages; i++) {  // Loop through new messages
    chat_id = bot.messages[i].chat_id;  // Get chat ID from the message
    text = bot.messages[i].text;  // Get message text
  }

  // Check if the command is "/Gettemp"
  if (text == "/Gettemp") {
    if (chid == chat_id) {  // Check if the chat ID matches
      bot.sendMessage(chat_id, String(message), "");  // Send temperature message
      text = "";  // Clear message text
      chat_id = "";  // Clear chat ID
    }
  }

  // Check if the command is "/Gethumi"
  if (text == "/Gethumi") {
    if (chid == chat_id) {  // Check if the chat ID matches
      bot.sendMessage(chat_id, String(message1), "");  // Send humidity message
      text = "";  // Clear message text
      chat_id = "";  // Clear chat ID
    }
  }
}

// Setup function, runs once at the start
void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud rate
  dht.begin();  // Initialize the DHT sensor
  WiFi.mode(WIFI_STA);  // Set Wi-Fi mode to station
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as output

  // Print connecting message and attempt to connect to Wi-Fi
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(ssid);  // Print the SSID
  WiFi.begin(ssid, password);  // Begin Wi-Fi connection with credentials

  // Set up secure client for Telegram
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);  // Add root certificate for Telegram API
  while (WiFi.status() != WL_CONNECTED) {  // Wait until Wi-Fi is connected
    Serial.print(".");  // Print dots while connecting
    delay(500);  // Delay for half a second
  }
  
  // Print Wi-Fi connection status
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());  // Print local IP address

  // Print retrieving time message and configure time
  Serial.print("Retrieving time: ");
  configTime(0, 0, "pool.ntp.org");  // Get UTC time from NTP server
  time_t now = time(nullptr);  // Get current time
  while (now < 24 * 3600) {  // Wait until the time is valid
    Serial.print(".");  // Print dots while waiting
    delay(100);  // Delay for 100 milliseconds
    now = time(nullptr);  // Update current time
  }
  Serial.println(now);  // Print the current time
}

// Main loop, runs continuously after setup
void loop() {
  float h = dht.readHumidity();  // Read humidity from DHT sensor
  float t = dht.readTemperature();  // Read temperature from DHT sensor

  if (isnan(h) || isnan(t)) {  // Check if reading failed
    Serial.println("Failed to read from DHT sensor!");  // Print error message
    return;  // Exit loop
  }

  message = t;  // Store temperature in message
  message1 = h;  // Store humidity in message1

  // Check if temperature exceeds a threshold (34°C)
  if (t > 34 ) {  
    digitalWrite(LED_PIN, HIGH);  // Turn the LED ON (indicating high temperature)
    bot.sendMessage(chid, "Temperature is High !!", "");  // Send alert to Telegram
  } else {
    digitalWrite(LED_PIN, LOW);  // Turn the LED OFF (temperature is normal)
  }

  // Check for new Telegram messages every BOT_MTBS milliseconds
  if (millis() - bot_lasttime > BOT_MTBS) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);  // Get new messages

    while (numNewMessages) {  // Process new messages
      Serial.println("got response");  // Print response message
      handleNewMessages(numNewMessages);  // Handle new messages
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);  // Check for more new messages
    }

    bot_lasttime = millis();  // Update last time messages were checked
  }

  // Send data to ThingSpeak every timerDelay milliseconds
  if ((millis() - lastTime) > timerDelay) {
    if (WiFi.status() != WL_CONNECTED) {  // Check if Wi-Fi is still connected
      Serial.print("Attempting to connect");  // Print attempt message
      while (WiFi.status() != WL_CONNECTED) {  // While not connected
        WiFi.begin(ssid, password);  // Try to connect to Wi-Fi
        delay(5000);  // Delay for 5 seconds before retrying
      }
      Serial.println("\nConnected.");  // Print connected message
    }
    
    // Print temperature and humidity readings
    Serial.println(t);  
    Serial.println(h);
    
    // Set fields for ThingSpeak
    ThingSpeak.setField(1, t);  // Set field 1 to temperature
    ThingSpeak.setField(2, h);  // Set field 2 to humidity
    
    // Write the fields to ThingSpeak
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);  // Send data to ThingSpeak
    lastTime = millis();  // Update the last time data was sent
  }
}
