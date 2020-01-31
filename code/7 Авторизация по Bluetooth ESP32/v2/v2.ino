#include <FS.h>                     //http://esp8266.github.io/Arduino/versions/2.1.0/doc/filesystem.html  
#include <ArduinoJson.h>            //https://bblanchon.github.io/ArduinoJson/
#include "SPIFFS.h"
#include <Arduino.h>
#include <sstream>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
 
BLEScan* esp_scan;
String Bluetooth_device_mac;
int Bluetooth_device_rssi;

 
 

void setup() {
     Serial.begin(9600);
     SPIFFS.begin();
     pinMode(2, OUTPUT);
     BLEDevice::init("");
     esp_scan = BLEDevice::getScan();
     esp_scan->setActiveScan(true); //активное сканирование потребляет больше энергии, но быстрее результаты
     esp_scan->setInterval(100); // интервал для сканирования (мсек)
     esp_scan->setWindow(30);  // меньше или равно значению setInterval
      
}
void loop() {
     Bluetooth_scan();
}
