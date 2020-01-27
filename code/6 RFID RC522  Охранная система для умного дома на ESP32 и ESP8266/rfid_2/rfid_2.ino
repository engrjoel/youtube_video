#include <FS.h>                     //http://esp8266.github.io/Arduino/versions/2.1.0/doc/filesystem.html  
#include <ArduinoJson.h>            //https://bblanchon.github.io/ArduinoJson/
#include <SPI.h>                    //http://www.arduino.cc/en/Reference/SPI
#include <MFRC522.h>                //https://github.com/miguelbalboa/rfid
#include "SPIFFS.h" // для ESP32


#define RST_PIN         4         
#define SS_PIN          2    
MFRC522 mfrc522(SS_PIN, RST_PIN);   
int card,uid;
char floatbufVar[32]; 


void setup() {
     Serial.begin(115200);
     SPIFFS.begin();
     SPI.begin();  
     mfrc522.PCD_Init();    
}

void loop() {
     rfid_uid(); 
}
