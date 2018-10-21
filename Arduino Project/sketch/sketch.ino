// Doru Muntean march 2018
//https://github.com/wemos/D1_mini_Examples
//https://github.com/firebase/firebase-arduino/tree/master/examples

#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


//Firebase Realtime Database setup
#define FIREBASE_HOST "YOUR_HOST"
#define FIREBASE_AUTH "YOUR_AUTH"

//WI-FI setup
#define WIFI_SSID "YOUR_SSID"
#define WIFI_PASSWORD "YOUR_PASSWORD"

//WS2812B RGB shield setup
#define PIN D2
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

//Other variables
int n = 0;
String sensorData = "sensors/sensor1/Sensor Data ";

void setup() {
  Serial.begin(9600);

  //Initialize the NeoPixel library for the WS2812B RGB shield
  pixels.begin();

  //Connect to WI-FI.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}


void loop() {

  for (int i = 1; i<=6; i++) {
    // update value
    Serial.println(sensorData+i);
    Firebase.setInt(sensorData+i, n++);

    // handle error
    if (Firebase.failed()) {
      Serial.print("Failed to update data to " + sensorData + i);
      Serial.println(Firebase.error());

      //Flash red pixel on the RGB shield
      pixels.setPixelColor(0, pixels.Color(255,0,0));
      pixels.show();
      delay(50);
      pixels.setPixelColor(0, pixels.Color(0,0,0));
      pixels.show();

      return;

    } else {
      //Flash green pixel on the RGB shield
      pixels.setPixelColor(0, pixels.Color(0,255,0));
      pixels.show();
      delay(50);
      pixels.setPixelColor(0, pixels.Color(0,0,0));
      pixels.show();
    }
  }

  delay(5000);
}
