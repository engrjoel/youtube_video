 void Bluetooth_scan() {
      BLEScanResults foundDevices = esp_scan->start(2);//(секунд)
      int devices_found_number = foundDevices.getCount();//Количество найденных устройств
      for (int i = 0; i < devices_found_number; i++){
           BLEAdvertisedDevice d = foundDevices.getDevice(i);
           Bluetooth_device_mac = d.getAddress().toString().c_str();
           Serial.println(Bluetooth_device_mac);//Список обнаруженных устройств
           if (Bluetooth_device_mac == "d6:39:d8:b5:94:82") {
                Serial.println("Device Found #1");//Устройство найдено # 1
                Bluetooth_device_rssi = d.getRSSI();
                i=devices_found_number;
                 
                 if (Bluetooth_device_rssi > -50){
                     Serial.println("signal strength is sufficient #2");//Уровень сигнала достаточен # 2
                     digitalWrite(2, HIGH);   
                     delay(1000);                     
                     digitalWrite(2, LOW);   
                    }
               }
           esp_scan->clearResults();
           }
} 
