void Bluetooth_scan() {
      BLEScanResults foundDevices = esp_scan->start(2);//(секунд)
      int devices_found_number = foundDevices.getCount();//Количество найденных устройств
      for (int i = 0; i < devices_found_number; i++){
           BLEAdvertisedDevice d = foundDevices.getDevice(i);
           Bluetooth_device_mac = d.getAddress().toString().c_str();
           Serial.println(Bluetooth_device_mac);//Список обнаруженных устройств
           
           if (Bluetooth_device_mac == Bluetooth_mac_database) {
                Serial.println("#2 Bluetooth Device Found ");//Bluetooth устройство найдено #2
                Bluetooth_device_rssi = d.getRSSI();//Уровень сигнала Bluetooth устройства
                i=devices_found_number;
                
                if (Bluetooth_device_rssi > -50){
                    Serial.println("#3 Bluetooth rssi OK");//#3 Уровень сигнала достаточен  
                    delay(1000); 
                    }
               }
           esp_scan->clearResults();
           }
} 
