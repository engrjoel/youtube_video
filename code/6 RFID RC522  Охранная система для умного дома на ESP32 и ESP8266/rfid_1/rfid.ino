void rfid_uid() {// Считывает  UID карты    
     if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) { 
           return;
        }
     String uid_;  
     uid_ += mfrc522.uid.uidByte[1];     
     uid_ += mfrc522.uid.uidByte[2];
     uid_ += mfrc522.uid.uidByte[3];
     uid_ += mfrc522.uid.uidByte[4];  
            
     uid_.toCharArray(floatbufVar,sizeof(floatbufVar));
     card=atof(floatbufVar);
     Serial.print("Card UID: ");
     Serial.println(card );
     
     if (card == 89181870) {//Если  есть в базе
         Serial.println("Open");
         delay(1000); 
         }else {
          Serial.println("closed"); 
          delay(1000); 
         }
}
