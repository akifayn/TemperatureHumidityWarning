# 🌡️ TemperatureHumidityWarning – IoT-Based Temperature and Humidity Alert System

This project measures ambient temperature and humidity using a DHT11 sensor. The measured values are displayed on an LCD screen and can also be monitored remotely via the Blynk application. When the temperature exceeds a predefined threshold, an alert is triggered with a buzzer and LED. During the alert, a Super Mario melody is played.

## [📹 Project Video](https://www.youtube.com/watch?v=UFVGz6wSowM)

## 🎯 Objective
- Measure temperature and humidity values
- Display values on an LCD screen
- Trigger alerts when the temperature exceeds a defined limit
- Monitor values remotely using the Blynk mobile app

## 🧰 Components Used
- ESP8266 (NodeMCU)
- DHT11 Sensor
- I2C LCD 16x2 Display
- Active  Buzzer
- LED
- Wi-Fi Connection
- Blynk Mobile App

## 🔌 Hardware Connections

| Bileşen     | ESP8266 GPIO | Açıklama           |
|-------------|---------------|--------------------|
| DHT11       | GPIO4 (D2)    | Temperature & Humidity|    |
| LCD (I2C)   | SDA: D3 / SCL: D4 | LCD display        |
| Buzzer      | GPIO5 (D1)    | Audible alert        |
| LED         | GPIO12 (D6)   | Visual alert       |

## 📱 Blynk Settings
- Template ID: `TMPL6K8JefXnv`
- Auth Token: Obtain from the Blynk app
- Virtual Pin V0: Temperature
- Virtual Pin V1: Humidity
- Virtual Pin V2: LED Status

## 🛠️ Installation
1. In the Arduino IDE, install the following libraries:
   - `DHT.h`
   - `LiquidCrystal_I2C.h`
   - `BlynkSimpleEsp8266.h`
   - `ESP8266WiFi.h`
2. Replace the auth, ssid, and pass variables in the code with your own credentials.
3. Connect the ESP8266 and upload the .ino file to the board.

## 🎵 Alarm System
When the temperature exceeds the set limit, a Super Mario melody is played through the buzzer and the LED lights up.

## 👨‍💻 Developers
- Muhammet Akif Ayan
- Oğuzhan Yalçın
