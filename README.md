# 🌡️ ThermoTrack – IoT Temperature & Humidity Monitor 
> Real-time sensing, cloud logging, and instant Telegram alerts — all on an ESP32.

![GitHub Repo stars](https://img.shields.io/github/stars/Shristirajpoot/thermotrack?style=social)
![GitHub last commit](https://img.shields.io/github/last-commit/Shristirajpoot/thermotrack?color=brightgreen)
![License](https://img.shields.io/github/license/Shristirajpoot/thermotrack)

---

## 📚 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Setup Guide](#setup-guide)
- [How to Use](#how-to-use)
- [Libraries Used](#libraries-used)
- [License](#license)

---

## 📝 Overview
**ThermoTrack** is an IoT-based system that **monitors temperature and humidity**, pushes readings to **ThingSpeak**, and sends critical-threshold alerts through a **Telegram bot**. It’s perfect for smart homes, greenhouses, server rooms, or any scenario where timely environmental awareness matters.

<img src="https://github.com/user-attachments/assets/920ba5e2-f2f9-4361-a98d-e2d93d6e4e8a" alt="LCD + Sensor" width="400"/>


---

## 🌟 Features
- 📈 **Real-time monitoring** on LCD  
- ☁️ **Cloud logging** with ThingSpeak  
- 📲 **Telegram alerts** above 34 °C  
- 🔔 **Visual & audible** (LED + buzzer) warnings  
- 🔌 **Wi-Fi-enabled** via ESP32  

---
## 🔩 Components
| Part | Role |
|------|------|
| ESP32 | Wi-Fi microcontroller |
| DHT11 | Temp + humidity sensor |
| 16×2 LCD | On-device read-out |
| LED & Buzzer | Local alerts |
| ThingSpeak | Cloud dashboard |
| Telegram Bot | Remote notifications |

---

# Circuit Diagram

**Connection Details:**

- **DHT11 Sensor**:
  - VCC -> 3.3V on ESP32
  - Data -> GPIO pin on ESP32
  - GND -> GND on ESP32
- **LCD Display**:
  - VCC -> VCC on ESP32
  - GND -> GND on ESP32
  - SCL -> SCL on ESP32
  - SDA -> SDA on ESP32
- **Buzzer and LED**:
  - Buzzer and LED are connected to separate GPIO pins on the ESP32, with a shared GND connection.
  
   <img src="https://github.com/user-attachments/assets/a43efcdd-6e1f-430a-b82c-d794a80559ac" alt="Circuit Diagram" width="500"/>


---

## 🚀 Setup Guide

### 1️⃣ ThingSpeak
1. Create a channel with **Temperature** & **Humidity** fields.  
2. Note your **Channel ID** and **Write API Key**.  
  <img src="https://github.com/user-attachments/assets/d387abde-6721-4503-8530-27401b26fc40" alt="ThingSpeak" width="400"/>


### 2️⃣ Telegram Bot
1. Talk to **@BotFather** → `/newbot` → get **Bot Token**.  
2. DM your bot once, then obtain your **Chat ID**.  
3. Add both token & chat ID to the code.

### 3️⃣ Wi-Fi & Code
- Open **ESP32_Temperature_Monitor.ino** in Arduino IDE.  
- Fill in `WIFI_SSID`, `PASSWORD`, ThingSpeak keys, and Telegram creds.  
- Flash to your ESP32.

---

## ▶️ How to Use

1. Power the ESP32 — it connects to Wi-Fi, starts logging, and shows readings on the LCD.  
2. **Watch data** on your ThingSpeak dashboard in real time.  
3. **Receive alerts** when temperature > 34 °C: LED + buzzer + Telegram message.  
<img src="https://github.com/user-attachments/assets/6d2ac8b6-6b79-424a-8b88-4b8d2e796557" alt="TelegramBot" width="350"/>


### Telegram Commands
| Command | Response |
|---------|----------|
| `/Gettemp` | Current temperature |
| `/Gethumi` | Current humidity |

---

## 📚 Libraries Used
- `WiFi.h` – Wi-Fi connectivity  
- `ThingSpeak.h` – Cloud REST client  
- `WiFiClientSecure.h` – HTTPS support  
- `UniversalTelegramBot.h` – Telegram API  
- `DHT.h` – Sensor driver  

> **Install** via *Arduino IDE → Library Manager*.

---
## 👩‍💻 Author
### Shristi Rajpoot
- 📧 Email: shristirajpoot369@gmail.com
- 🔗 GitHub: @Shristirajpoot

---

## 📜 License
Distributed under the **MIT License** — see [`LICENSE`](./LICENSE).

---

### ⭐ Like what you see? **Star** the repo, fork it, or open an issue — contributions welcome!
