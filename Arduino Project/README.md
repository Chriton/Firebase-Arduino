# Arduino Project

This is an Arduino project that saves and updates data to a Firebase Realtime Database

## Arduino IDE Setup

- Install [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- Add the ArduinoJson library to Arduino IDE (Sketch -> Include library -> Manage Libraries -> search and install ArduinoJson)
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

