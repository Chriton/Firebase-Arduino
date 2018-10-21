# Arduino Project

This is an Arduino project that writes and updates data to a Firebase Realtime Database.

## Arduino IDE Setup & adding libraries

- Install [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- Some additional libraries are needed for the example sketches to work. You can add a library to Arduino IDE in 2 ways:
- either by downloading the zip file from the github repository/releases and then in Arduino IDE go to Sketch -> Include library -> Manage Libraries -> Add .ZIP Library
- or in Arduino IDE go to Sketch -> Include library -> Manage Libraries -> search for the library name -> Install

More info [here](https://www.arduino.cc/en/Guide/Libraries).

Add the following libraries:

- [ArduinoJson](https://github.com/bblanchon/ArduinoJson). Note that there might be some issues with the latest version (I've downgraded to 5.13.2)
- [FirebaseArduino](https://github.com/firebase/firebase-arduino). I've used v.0.3 downloaded from the repository.
- for [Wemos ws2812b RGB Shield](https://wiki.wemos.cc/products:d1_mini_shields:ws2812b_rgb_shield) we need [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) library.
- for [Wemos OLED Shield](https://wiki.wemos.cc/products:d1_mini_shields:oled_shield) we need [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library) and [Adafruit SSD1306 Wemos Mini OLED](https://github.com/stblassitude/Adafruit_SSD1306_Wemos_OLED) library.

## Removing an arduino library 

- To remove a library you need delete the library's folder and then restart Arduino IDE. On mac OS the default location of the libraries is ~/Documents/Arduino/libraries.

Note that you can always change the location of the libraries by going to Arduino IDE -> Preferences -> Settings -> Sketchbook location -> and set your own location. 
In there a "library" folder will be created and used by Arduino IDE.

## Arduino Hardware

- [Wemos D1 mini v.2.30](https://wiki.wemos.cc/products:retired:d1_mini_v2.3.0) (with 4mb flash based on ESP8266 ESP-12S)
- [Wemos ws2812b RGB Shield](https://wiki.wemos.cc/products:d1_mini_shields:ws2812b_rgb_shield)
- [Wemos OLED Shield](https://wiki.wemos.cc/products:d1_mini_shields:oled_shield)

Add support for [Wemos D1 mini v.2.30](https://wiki.wemos.cc/products:retired:d1_mini_v2.3.0) -> Arduino IDE -> Tools -> Board -> 
Board Manager -> search and install ESP8266.

Also make sure you set these in Arduino IDE -> Tools:
- Board: Wemos D1 R2 & mini
- Flash Size: 4M (3M SPIFFS)
- Upload Speed: 115200 (you can try a faster speed if it works)
- Port: /dev/cu.wchusbserial1410 (Note that the right port will appear only when the device is connected to USB. Download the driver from [here](https://wiki.wemos.cc/downloads))
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

Open one of the sketch.ino examples with Arduino IDE and set your own data in:
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
- Note that there might be some issues with the latest version of [ArduinoJson](https://github.com/bblanchon/ArduinoJson) (I've downgraded to 5.13.2). 
To downgrade, go to Sketch -> Include library -> Manage Libraries -> search for [ArduinoJson](https://github.com/bblanchon/ArduinoJson) 
-> click Select version -> 5.13.2 -> restart Arduino IDE.

### [firebase-arduino](https://github.com/firebase/firebase-arduino) 
At this moment the version which I'm using (v0.3) [firebase-arduino](https://github.com/firebase/firebase-arduino) seems not to work anymore, so if you get an error in the Arduino IDE serial monitor log like "setting /number failed" (and you cannot read/write to firebase) try this:
[firebase-arduino change fingerprint 1](https://github.com/FirebaseExtended/firebase-arduino/issues/373#issuecomment-411006219) or [firebase-arduino change fingerprint 2](https://github.com/FirebaseExtended/firebase-arduino/issues/369#issuecomment-410087936). So basically:
 - first check the new Firebase fingerprint here [Server Fingerprints](https://www.grc.com/fingerprints.htm). Copy your database address in there (eg. mydatabase.firebaseio.com) and click on Fingerprint Site. For me at this moment it shows: 6F:D0:9A:52:C0:E9:E4:CD:A0:D3:02:A4:B7:A1:92:38:2D:CA:2F:26
 - Do not just copy this one, maybe it has changed again, so just verify it yourself.
 - remove the [firebase-arduino](https://github.com/firebase/firebase-arduino) library added initially like shown in the "Removing an arduino library" section.
 - download a [firebase-arduino](https://github.com/firebase/firebase-arduino) zip release from the [repository](https://github.com/firebase/firebase-arduino), then extract all the files into a folder of your choice and replace the old fingerprint which can be found in the extracted files -> src/FirebaseHttpClient.h -> kFirebaseFingerprint
 - after you add the new fingerprint into FirebaseHttpClient.h, save it and put all the files back into a zip file and reimport the library like shown in the "Arduino IDE Setup & adding libraries" section.
 - restart Arduino IDE and recompile your sketch.



