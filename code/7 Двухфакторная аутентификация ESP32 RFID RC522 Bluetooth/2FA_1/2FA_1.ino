#include <SPI.h>                    //http://www.arduino.cc/en/Reference/SPI
#include <MFRC522.h>                //https://github.com/miguelbalboa/rfid
#include <Arduino.h>
#include <sstream>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

#define RST_PIN         4         
#define SS_PIN          2    
MFRC522 mfrc522(SS_PIN, RST_PIN);   

BLEScan* esp_scan;
String Bluetooth_device_mac;
int Bluetooth_device_rssi;
int card;
char floatbufVar[32]; 
 


void setup() {
     Serial.begin(115200);
     SPI.begin();  
     mfrc522.PCD_Init();   
     BLEDevice::init("");
     esp_scan = BLEDevice::getScan();
     esp_scan->setActiveScan(true); //активное сканирование потребляет больше энергии, но быстрее результаты
     esp_scan->setInterval(200); // интервал для сканирования (мсек)
     esp_scan->setWindow(30);  // меньше или равно значению setInterval 
     Serial.println("#0 OK");
}
void loop() {
     rfid_uid(); 
      
}
