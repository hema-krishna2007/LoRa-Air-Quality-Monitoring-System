# 🌱 LoRa-Based Environmental & Air Quality Monitoring System

This project presents a **LoRa-based wireless environmental and air quality monitoring system** developed as a **self-initiated project driven by personal interest in Embedded Systems and IoT**.  
It is **not an academic or curriculum-based project**, but a hands-on effort to understand real-world long-range wireless communication, sensor integration, and cloud-based data visualization.

The system collects environmental and air quality parameters at a remote location and transmits the data using **LoRa (LPWAN)** technology to a gateway, which uploads the data to the **ThingSpeak IoT cloud** for real-time mobile visualization.

---

## 🔹 Project Overview

- **Transmitter Node**  
  Crowdunio UNO + LoRa ThingBot v1.1  
  Sensors:  
  - DHT11 (Temperature & Humidity)  
  - Adafruit PM25AQI (PM1.0, PM2.5, PM10)

- **Receiver Gateway**  
  ESP32-D + LoRa ThingBot v1.1

- **Cloud Platform**  
  ThingSpeak IoT Cloud (Real-time visualization & analysis)

---

## 🔁 System Architecture Flow
Sensors

↓

Crowdunio UNO

↓

LoRa Transmitter

↓

LoRa Receiver

↓

ESP32 (Wi-Fi)

↓

ThingSpeak Cloud

↓

Mobile / Web Visualization


---

## 🔹 Hardware & Technologies Used

- Crowdunio UNO  
- LoRa ThingBot v1.1 (LPWAN Module)  
- ESP32-D (Wi-Fi enabled microcontroller)  
- DHT11 Temperature & Humidity Sensor  
- Adafruit PM25AQI Air Quality Sensor  
- ThingSpeak IoT Cloud  
- Arduino IDE  

---

## ⭐ Key Features

- Long-range, low-power wireless communication using LoRa  
- Multi-sensor data acquisition (environmental + air quality)  
- Reliable gateway-based cloud integration using ESP32  
- Real-time mobile and web-based visualization  
- Scalable architecture suitable for large-area monitoring  

---

## 🔹 Why This Project is Special

Unlike typical **Wi-Fi-only IoT systems**, this project uses **LoRa technology**, enabling **long-distance communication with very low power consumption**.  
This makes it highly suitable for applications where internet connectivity is limited or unavailable.

---

## 🔹 Most Useful In

- Smart city air quality monitoring  
- Industrial and campus environments  
- Remote and rural area monitoring  
- Environmental data logging and research  

---

## 📊 Live IoT Dashboard (ThingSpeak)

👉 https://thingspeak.com/channels/3215658  

*(Real-time sensor data visualization and analysis via cloud dashboard)*

---

## 📁 Repository Structure

LoRa-Air-Quality-Monitoring-System

│
├── README.md

├── images

      │ ├── block_diagram.png

      │ ├── complete_setup.jpg

      │ └── mobile_thingspeak_dashboard.png
│

└── code

     ├── transmitter_lora_uno.ino
   
     └── receiver_lora_esp32.ino





---

## 📄 Source Code

- **Transmitter Code**  
  `code/lora_transmitter_dht_aqi.ino`  
  (Crowdunio UNO + LoRa + DHT11 + PM25AQI)

- **Receiver Code**  
  `code/lora_receiver_esp32_thingspeak.ino`  
  (LoRa Receiver + ESP32 + ThingSpeak)

---

## 📷 Project Images

- Block Diagram  
- Complete Hardware Setup  
- ThingSpeak Mobile Dashboard  

(All images are available in the `images` folder)

---

## 🚀 Learning Outcomes

This project strengthened our understanding of:

- IoT system architecture  
- LPWAN (LoRa) communication  
- Embedded systems programming  
- Sensor interfacing  
- Cloud-based data visualization  

---

## 🤝 Feedback

Suggestions, improvements, and discussions are always welcome! 😊  

---

## 🔖 Tags

#IoT #LoRa #ESP32 #Arduino #EmbeddedSystems  
#AirQualityMonitoring #ThingSpeak #ECE #IoTProjects
