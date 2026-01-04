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
  `cpde/lora_transmitter_dht_aqi.ino`  
  (Crowdunio UNO + LoRa + DHT11 + PM25AQI)

- **Receiver Code**  
  `cpde/lora_receiver_esp32_thingspeak.ino`  
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
## 🔧 Installation Instructions

### 1️⃣ Arduino IDE Setup
1. Download and install **Arduino IDE** from:  
   https://www.arduino.cc/en/software
2. Open Arduino IDE  
3. Go to **File → Preferences**
4. (For ESP32) Add the following URL in **Additional Board Manager URLs**:

https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

5. Go to **Tools → Board → Boards Manager**
6. Install the following boards:
- **Arduino AVR Boards** (for Crowdunio / Arduino UNO)
- **ESP32 by Espressif Systems**

---

### 2️⃣ Required Libraries
Install the following libraries via  
**Sketch → Include Library → Manage Libraries**

- DHT sensor library – by Adafruit  
- Adafruit Unified Sensor  
- Adafruit PM25 AQI  
- LoRa – by Sandeep Mistry *(or E22 library if used)*  
- ThingSpeak  
- WiFi *(default for ESP32)*  

---

### 3️⃣ Uploading the Code

#### Transmitter Node (Crowdunio UNO)
1. Connect the **transmitter board** to the PC  
2. Select the correct **Board** and **COM Port**  
3. Upload `transmitter_lora_uno.ino`  
4. Disconnect the transmitter  

#### Receiver Node (ESP32-D)
1. Connect the **ESP32 receiver** to the PC  
2. Select **ESP32 Dev Module**  
3. Enter Wi-Fi credentials and ThingSpeak API Key in the code  
4. Upload `receiver_lora_esp32.ino`  
5. Power both transmitter and receiver nodes  

---

## 🔌 Wiring Connections

### 📍 Transmitter Side (Crowdunio UNO + Sensors + LoRa)

| Component        | Arduino UNO Pin |
|------------------|-----------------|
| DHT11 vcc ,gnd   | 5v ,gnd         |
| DHT11 DATA       | D3              |
| PMS5003 VCC,GND  | 5V,GND          |
| PMS5003          | D4              |
| LoRa NSS (CS)    | D10             |
| LoRa MOSI        | D11             |
| LoRa MISO        | D12             |
| LoRa SCK         | D13             |
| LoRa RST         | D9              |
| LoRa DIO0        | D2              |

⚠️ *Pin numbers may vary depending on the module and code configuration.*

---

### 📍 Receiver Side (LoRa ThingBot v1.1 → ESP32-D)

| LoRa Pin | ESP32-D Pin | Description |
|---------|-------------|-------------|
| VCC     | 3.3V        | Power supply (**Do NOT use 5V**) |
| GND     | GND         | Ground |
| SCK     | GPIO18      | SPI Clock |
| MISO    | GPIO19      | SPI MISO |
| MOSI    | GPIO23      | SPI MOSI |
| NSS / CS| GPIO5       | Chip Select |
| RST     | GPIO14      | Reset |
| DIO0    | GPIO2       | Interrupt (RX/TX Done) |

```markdown
⚠️ Important Notes:
- Power the LoRa ThingBot v1.1 using **3.3V only**
- Supplying 5V may permanently damage the LoRa module
- SPI pins must match the configuration used in the receiver code.

## 🛠 Troubleshooting

- **No data on ThingSpeak**
  - Check Wi-Fi credentials and API key
  - Ensure ESP32 is connected to the internet

- **LoRa not receiving data**
  - Verify SPI pin mapping
  - Ensure both nodes use the same frequency and spreading factor

- **PM sensor not responding**
  - Check UART connections
  - Ensure proper power supply



## 🤝 Feedback

Suggestions, improvements, and discussions are always welcome! 😊  

---

## 🔖 Tags

#IoT #LoRa #ESP32 #Arduino #EmbeddedSystems  
#AirQualityMonitoring #ThingSpeak #ECE #IoTProjects
