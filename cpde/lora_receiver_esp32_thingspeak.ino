#include <SPI.h>
#include <LoRa.h>
#include <WiFi.h>
#include <HTTPClient.h>

// ---------- LoRa Pins ----------
#define SS   5
#define RST  14
#define DIO0 2

// ---------- WiFi Details ----------
const char* ssid = "wifi name";
const char* password = "password";

// ---------- ThingSpeak ----------
String apiKey = "api_key";
String server = "http://api.thingspeak.com/update";

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // -------- WiFi Connection --------
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");

  // -------- LoRa Setup --------
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  Serial.println("LoRa Receiver Started");
}

void loop() {

  int packetSize = LoRa.parsePacket();
  if (packetSize) {

    String receivedData = "";

    while (LoRa.available()) {
      receivedData += (char)LoRa.read();
    }

    Serial.println("Received: " + receivedData);

    // -------- Parse CSV Data --------
    float humidity, temperature, pm1, pm25, pm10;
    int counter;

    sscanf(receivedData.c_str(),
           "%f,%f,%f,%f,%f,%d",
           &humidity, &temperature, &pm1, &pm25, &pm10, &counter);

    // -------- Print Values --------
    Serial.print("Temperature: "); Serial.println(temperature);
    Serial.print("Humidity: "); Serial.println(humidity);
    Serial.print("PM1.0: "); Serial.println(pm1);
    Serial.print("PM2.5: "); Serial.println(pm25);
    Serial.print("PM10: "); Serial.println(pm10);
    Serial.print("Packet #: "); Serial.println(counter);

    // -------- Send to ThingSpeak --------
    if (WiFi.status() == WL_CONNECTED) {

      HTTPClient http;
      String url = server + "?api_key=" + apiKey +
                   "&field1=" + String(temperature) +
                   "&field2=" + String(humidity) +
                   "&field3=" + String(pm1) +
                   "&field4=" + String(pm25) +
                   "&field5=" + String(pm10);

      http.begin(url);
      int httpCode = http.GET();

      if (httpCode > 0) {
        Serial.println("Data sent to ThingSpeak");
      } else {
        Serial.println("ThingSpeak Error");
      }

      http.end();
    }
  }

  delay(1000); // ThingSpeak minimum update interval
}



