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
    
     File configFile = SPIFFS.open("/database.json", "r");
     size_t size = configFile.size();
     std::unique_ptr<char[]> buf(new char[size]);
     configFile.readBytes(buf.get(), size);
     
     DynamicJsonDocument json(1024);
     DeserializationError error = deserializeJson(json, buf.get());
     int quantity_ = json["quantity"];//количество записей в базе
     for (int i=0; i<=quantity_; i++){
          uid = json["rfid"][i];
          if (uid == card ) {//Если  есть в базе
              Serial.println("Open");
              delay(1000);  
              i=uid;
              i++;
             }
          if (i == quantity_) {//Если нет в базе 
              Serial.println("closed"); 
              delay(1000); 
          }
      }
}
