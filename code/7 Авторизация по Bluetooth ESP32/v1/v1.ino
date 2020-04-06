#include <Arduino.h>
#include <sstream>
#include <BLEDevice.h>//https://github.com/nkolban/ESP32_BLE_Arduino
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

BLEScan* esp_scan;
String Bluetooth_device_mac;
int Bluetooth_device_rssi;


void setup() {
     Serial.begin(9600);
     pinMode(2, OUTPUT);
     BLEDevice::init("");
     esp_scan = BLEDevice::getScan();
     esp_scan->setActiveScan(true); //активное сканирование потребляет больше энергии, но быстрее результаты
     esp_scan->setInterval(200); // интервал для сканирования (мсек)
     esp_scan->setWindow(30);  // меньше или равно значению setInterval
      
}
void loop() {
     Bluetooth_scan();
}
