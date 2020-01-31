 void Bluetooth_scan() {
      BLEScanResults foundDevices = esp_scan->start(1);//(секунд)
      int devices_found_number = foundDevices.getCount();//Количество найденных устройств
      
      File configFile = SPIFFS.open("/database.json", "r");
      size_t size = configFile.size();
      std::unique_ptr<char[]> buf(new char[size]);
      configFile.readBytes(buf.get(), size); 
      DynamicJsonDocument json(1024);
      DeserializationError error = deserializeJson(json, buf.get()); 
      int quantity_ = json["quantity"];//количество записей в базе
      
      for (int i = 0; i < devices_found_number; i++){
           BLEAdvertisedDevice d = foundDevices.getDevice(i);
           Bluetooth_device_mac = d.getAddress().toString().c_str();
           Serial.println(Bluetooth_device_mac);//Список обнаруженных устройств
           
           for (int t = 0; t < quantity_; t++){
                String mac_ = json["mac"][t];//mac address Bluetooth устройства 
                
                if (Bluetooth_device_mac == mac_) {
                    Serial.println("Device Found #1");//Устройство найдено # 1
                    Bluetooth_device_rssi = d.getRSSI();
                    i=devices_found_number;
                    t=quantity_; 
                    
                    if (Bluetooth_device_rssi > -50){
                        Serial.println("signal strength is sufficient #2");//Уровень сигнала достаточен # 2
                        digitalWrite(2, HIGH);   
                        delay(1000);                     
                        digitalWrite(2, LOW);   
                       }
                   }
                } 
           esp_scan->clearResults();
          }
} 
