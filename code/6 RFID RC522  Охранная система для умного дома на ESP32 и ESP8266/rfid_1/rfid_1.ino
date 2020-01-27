#include <SPI.h>                    //http://www.arduino.cc/en/Reference/SPI
#include <MFRC522.h>                //https://github.com/miguelbalboa/rfid

#define RST_PIN         4         
#define SS_PIN          2    
MFRC522 mfrc522(SS_PIN, RST_PIN);   
int card;
char floatbufVar[32]; 


void setup() {
     Serial.begin(115200);
     SPI.begin();  
     mfrc522.PCD_Init();    
}
void loop() {
     rfid_uid(); 
}
