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
     DynamicJsonDocument json(2048);
     DeserializationError error = deserializeJson(json, buf.get());


     int quantity_ = json["quantity"];//количество записей в базе
     for (int i = 0; i < quantity_; i++){
          int rfid_ = json["record"][i]["rfid"];//uid карты
          if (rfid_ == card ) {//Если  есть в базе
                Serial.println("#1 RFID ON ");
                String Bluetooth_mac_ = json["record"][i]["mac"];//MAC-адрес Bluetooth устройства
                Bluetooth_mac_database = Bluetooth_mac_;
                Serial.print("Bluetooth MAC /database.json  ");
                Serial.println(Bluetooth_mac_);
                i=quantity_;
                Bluetooth_scan();
               }
           }
     
     
}
