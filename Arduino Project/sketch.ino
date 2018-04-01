// Doru Muntean march 2018
//https://github.com/wemos/D1_mini_Examples


#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


//Firebase Realtime Database setup
#define FIREBASE_HOST "fir-arduino-1.firebaseio.com"
#define FIREBASE_AUTH "JRt6JlnyJA2PemMGOG4IT3W6Sb3B51Mh0ZKvEFIF"

//WI-FI setup
#define WIFI_SSID "Chriton 2.4Ghz"
#define WIFI_PASSWORD "trutulescu"

//WS2812B RGB shield setup
#define PIN D2
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

//Other variables
int n = 0;

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

  // set value
  Firebase.setFloat("number", 42.0);

  //Flash green pixel on the RGB shield
  pixels.setPixelColor(0, pixels.Color(0,255,0));
  pixels.show();
  delay(50);
  pixels.setPixelColor(0, pixels.Color(0,0,0));
  pixels.show();

  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());
      return;
  }
  delay(1000);


  // update value
  Firebase.setFloat("number", 43.0);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());
      return;
  }
  delay(1000);


  // get value
  Serial.print("number: ");
  Serial.println(Firebase.getFloat("number"));
  delay(1000);


  // remove value
  Firebase.remove("number");
  delay(1000);


  // set string value
  Firebase.setString("message", "hello world");
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());
      return;
  }
  delay(1000);


  // set bool value
  Firebase.setBool("truth", false);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());
      return;
  }
  delay(1000);


  // append a new value to /logs
  String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());
      return;
  }

  //Other tests
 String someTest = Firebase.pushInt("sensors/timeTest", n++);
  delay(1000);
}
