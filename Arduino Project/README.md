# Arduino Project

This is an Arduino project that writes and updates data to a Firebase Realtime Database.

## Arduino IDE Setup

- Install [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- Add the [ArduinoJson](https://github.com/bblanchon/ArduinoJson) library to Arduino IDE (Sketch -> Include library -> Manage Libraries -> search and install ArduinoJson).
Note that there might me some issues with the latest version (I've downgraded to 5.13.2)
- Add the [firebase-arduino](https://github.com/firebase/firebase-arduino) demo files to Arduino IDE (download 
the zip repository to a folder of your choice and then Sketch -> Include library -> Manage Libraries -> Add .ZIP Library)
- Add support for [Wemos D1 mini v.2.30](https://wiki.wemos.cc/products:retired:d1_mini_v2.3.0) -> Arduino IDE -> Tools -> Board -> 
Board Manager -> search and install ESP8266
- Add suport for [Wemos ws2812b RGB Shield](https://wiki.wemos.cc/products:d1_mini_shields:ws2812b_rgb_shield) from the
 [Adafruit repository](https://github.com/adafruit/Adafruit_NeoPixel) (download the zip repository to a folder of your 
 choice and then Sketch -> Include library -> Manage Libraries -> Add .ZIP Library)

## Arduino Hardware

Using: 
- [Wemos D1 mini v.2.30](https://wiki.wemos.cc/products:retired:d1_mini_v2.3.0) (with 4mb flash. based on ESP8266 ESP-12S)
- [Wemos ws2812b RGB Shield](https://wiki.wemos.cc/products:d1_mini_shields:ws2812b_rgb_shield)

Make sure you set these in Arduino IDE -> Tools:
- Board: Wemos D1 R2 & mini
- Flash Size: 4M (3M SPIFFS)
- Upload Speed: 115200
- Port: /dev/cu.wchusbserial1410 (Note that the right port will appear when the device is connected to USB. Download the driver from [here](https://wiki.wemos.cc/downloads))
- Programmer ArduinoISP


## Firebase Realtime Database Setup
- Access [Firebase console](https://console.firebase.google.com/) and add a new app (or select your app)
- Go to Firebase Database -> Realtime Database and add the rules:
```
{
  "rules": {
    ".read": true,
    ".write": true
  }
}
```

Note that with these setting no auth is needed, if you want auth then add:

```
{
  "rules": {
    ".read": "auth != null",
    ".write": "auth != null"
  }
}
```

### For the arduino program we will need:
- FIREBASE_AUTH (Database Secret) -> [Firebase console](https://console.firebase.google.com/) -> your project -> Project Overview -> 
Project Settings -> Service Accounts -> Database Secrets -> Add Secret -> copy in your Arduino program to the FIREBASE_AUTH variable
eg.
```
#define FIREBASE_AUTH "axbea5FEPn3cxKEhIEXAMPLEOWTJFefrB68TV701"
```
- FIREBASE_HOST (Database link) -> [Firebase console](https://console.firebase.google.com/) -> your project -> Database -> Realtime 
Database -> Data -> copy the link (eg. https://wemosd1-1.firebaseio.com/) in your Arduino program but WITHOUT the "https://" and 
the last slash "/" to the FIREBASE_HOST variable like "wemosd1-1.firebaseio.com"
eg.
``` 
#define FIREBASE_HOST "wemosd1-1.firebaseio.com"
```

## Programming the Wemos D1 mini

Open the sketch.ino with Arduino IDE and set your own data in:
- FIREBASE_AUTH
- FIREBASE_HOST
- WIFI_SSID
- WIFI_PASSWORD

## Troubleshooting 

- When running the program on your Arduino if the data cannot be read/written to Firebase, double check the 4 const: 
- FIREBASE_AUTH
- FIREBASE_HOST
- WIFI_SSID
- WIFI_PASSWORD

### [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
- Note that there might me some issues with the latest version of [ArduinoJson](https://github.com/bblanchon/ArduinoJson) (I've downgraded to 5.13.2). 
To downgrade, go to Sketch -> Include library -> Manage Libraries -> search for [ArduinoJson](https://github.com/bblanchon/ArduinoJson) 
-> click Select version -> 5.13.2 -> restart Arduino IDE.

### [firebase-arduino](https://github.com/firebase/firebase-arduino) 
At this moment (v0.1) [firebase-arduino](https://github.com/firebase/firebase-arduino) seems not to work anymore, so if you get an error in the Arduino log like "setting /number failed" (and you cannot read/write to firebase) try this:
[firebase-arduino change fingerprint 1](https://github.com/FirebaseExtended/firebase-arduino/issues/373#issuecomment-411006219) or [firebase-arduino change fingerprint 2](https://github.com/FirebaseExtended/firebase-arduino/issues/369#issuecomment-410087936). So basically:
 - first check the new Firebase fingerprint here [Server Fingerprints](https://www.grc.com/fingerprints.htm). Copy your database address in there (eg. mydatabase.firebaseio.com) and click on Fingerprint Site. For me at this moment it shows: 6F:D0:9A:52:C0:E9:E4:CD:A0:D3:02:A4:B7:A1:92:38:2D:CA:2F:26
 - Do not just copy this one, maybe it has changed again, so just verify it yourself.
 - then replace the old fingerprint which can be found in the [firebase-arduino](https://github.com/firebase/firebase-arduino) zip file -> src/FirebaseHttpClient.h -> kFirebaseFingerprint
 - reimport the [firebase-arduino](https://github.com/firebase/firebase-arduino) library and recompile your sketch.



