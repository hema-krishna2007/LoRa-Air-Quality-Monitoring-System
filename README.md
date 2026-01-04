# 🌱 LoRa-Based Environmental & Air Quality Monitoring System

This is a self-initiated IoT project built out of personal interest in Embedded Systems and wireless communication. It is not an academic or curriculum-based project.

## 🔹 Project Overview
A LoRa-based system to monitor environmental parameters and air quality over long distances with real-time cloud visualization.

## 🔹 System Architecture
**Transmitter Side**
- Crowdunio UNO
- DHT11 (Temperature & Humidity)
- Adafruit PM25AQI (PM1.0, PM2.5, PM10)
- LoRa ThingBot v1.1

**Receiver Side**
- LoRa ThingBot v1.1
- ESP32 Development Board
- ThingSpeak IoT Cloud

## 🔁 Architecture Flow
Sensors → Crowdunio UNO → LoRa (Tx) → LoRa (Rx) → ESP32 → ThingSpeak → Mobile Visualization

## 📊 Live IoT Dashboard
https://thingspeak.com/channels/3215658  
*(Real-time sensor data visualization and analysis via cloud dashboard)*

## 🔹 Key Features
- Long-range, low-power LoRa communication
- Real-time air quality and environmental monitoring
- Cloud-based visualization using ThingSpeak
- Scalable for smart city and remote monitoring applications

## 🔹 Applications
- Smart cities
- Industrial air quality monitoring
- Campus and indoor monitoring
- Remote & rural area deployment

## 🛠 Tools & Technologies
- Arduino IDE
- LoRa (LPWAN)
- ESP32 Wi-Fi
- ThingSpeak Cloud

---

