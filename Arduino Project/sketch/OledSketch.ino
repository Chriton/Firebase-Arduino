// Doru Muntean oct 2018
// https://github.com/wemos/D1_mini_Examples
// https://github.com/firebase/firebase-arduino/tree/master/examples

// For Wemos Oled
#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

// For Wifi
#include <ESP8266WiFi.h>

// For Firebase
#include <ArduinoJson.h>
#include <FirebaseArduino.h>


#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

// Firebase Realtime Database setup
#define FIREBASE_HOST "YOUR_HOST"
#define FIREBASE_AUTH "YOUR_AUTH"

// WI-FI setup
#define WIFI_SSID "YOUR_SSID"
#define WIFI_PASSWORD "YOUR_PASSWORD"

// Other variables
int n = 0;
String sensorData = "sensors/sensor1/Sensor Data ";

void setup() {
  Serial.begin(9600);

  // display setup and stuff
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(1000);
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Connect to WI-FI.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");

  displayText("connecting...");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected!");
  Serial.println(WiFi.localIP());

  displayText("connected! " + WiFi.localIP().toString());
  delay(500);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}


void loop() {

  for (int i = 1; i<=6; i++) {
    // update value
    Serial.println(sensorData+i);
    Firebase.setInt(sensorData+i, n++);

    // Handle and display the error
    if (Firebase.failed()) {
      Serial.print("Failed to update data to " + sensorData + i);
      Serial.println(Firebase.error());

      // Display the error
      displayText(Firebase.error());

      return;

    } else {
      // Display success
      displayText("success: "+sensorData+i);
    }

    // Delay 1sec between writes
    delay(1000);
  }

  // Pause 5 sec after writing all values
  delay(5000);
}


void displayText(String text) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.println(text);
  display.display();
}
