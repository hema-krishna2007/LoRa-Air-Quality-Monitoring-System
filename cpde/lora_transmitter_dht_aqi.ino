#include <SPI.h>
#include <DHT.h>
#include <LoRa.h>
#include "Adafruit_PM25AQI.h"
#include <SoftwareSerial.h>

#define DHTTYPE DHT11
#define DHTPIN 3
DHT dht(DHTPIN, DHTTYPE);

int counter = 0;

SoftwareSerial pmSerial(4, 5);
Adafruit_PM25AQI aqi = Adafruit_PM25AQI();

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(10);
  Serial.println("Adafruit PMSA003I Air Quality Sensor");
  delay(1000);
  pmSerial.begin(9600);
  if (!aqi.begin_UART(&pmSerial)) {
    Serial.println("Could not find PM 2.5 sensor!");
    while (1) delay(10);
  }
  Serial.println("PM25 found!");

  dht.begin();
  delay(2000);
  while (!Serial);

  Serial.println("LoRa Sender");
  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;        
  }                                                  

  PM25_AQI_Data data;
  if (!aqi.read(&data)) {
    Serial.println("Could not read from AQI");
    delay(500);
    return;
  }

  String hum = String(h);
  String temp = String(t);
  String pm1 = String(data.pm10_standard);   // PM1.0
  String pm25 = String(data.pm25_standard);  // PM2.5
  String pm10 = String(data.pm100_standard); // PM10

  // send packet over LoRa
  LoRa.beginPacket();
  LoRa.print(hum); LoRa.print(",");
  LoRa.print(temp); LoRa.print(",");
  LoRa.print(pm1); LoRa.print(",");
  LoRa.print(pm25); LoRa.print(",");
  LoRa.print(pm10); LoRa.print(",");
  LoRa.print(counter);
  LoRa.endPacket();

  Serial.print("Sending packet: "); Serial.println(counter);
  Serial.print("Humidity: "); Serial.print(h);
  Serial.print("%, Temp: "); Serial.println(t);
  Serial.print(", PM1.0:"); Serial.print(data.pm10_standard);
  Serial.print(", PM2.5:"); Serial.print(data.pm25_standard);
  Serial.print(", PM10:"); Serial.println(data.pm100_standard);

  counter++;
  delay(20000);
}
