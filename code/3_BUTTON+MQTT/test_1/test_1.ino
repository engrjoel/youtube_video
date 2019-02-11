#include <ESP8266WiFi.h>            //https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi
#include <WiFiClient.h>
#include <ArduinoJson.h>            //https://bblanchon.github.io/ArduinoJson/
#include <PubSubClient.h>           //https://github.com/Imroy/pubsubclient
#include <Ticker.h>                 //https://github.com/esp8266/Arduino/tree/master/libraries/Ticker 

 
const char *ssid = ""; // Имя роутера
const char *password = ""; // Пароль роутера

String mqtt_server = ""; // Имя сервера MQTT
int mqtt_port = ; // Порт для подключения к серверу MQTT
String mqtt_user = ""; // Логин для подключения к серверу MQTT
String mqtt_pass = ""; // Пароль для подключения к серверу MQTT
String device_name = "";//имя  device_name
String group= "";//Группа group
 
String top1,top2,top3,top4; //адресное пространство MQTT 
int mqtt_data_status;

#define pin_button 13  
bool button_test;

WiFiClient mqtttestclient; 
PubSubClient mqttclient(mqtttestclient);

void callback(const MQTT::Publish& pub){
     String payload = pub.payload_string();
}

void setup(void) {
     Serial.begin(9600);
     
     top3 += "/home/"+group+ "/"+device_name+"/";//уровень устройства
     top2 += "/home/"+group+"/";//уровень комнаты     
     top1 += "/home/";//уровень дома   
     
     pinMode(pin_button, INPUT);           // назначить выводу порт ввода
     digitalWrite(pin_button, HIGH);       // включить подтягивающий резистор


     attachInterrupt(pin_button,button_testing,CHANGE);
 
     Serial.println("Connecting to ");
     Serial.println(ssid);
     WiFi.begin(ssid, password);
     while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
           }
     Serial.println("");
     Serial.println("WiFi connected");
     Serial.println("IP address: ");
     Serial.println(WiFi.localIP());
     
     mqtt_connect();
}

void loop(void){
     if (mqttclient.connected()){
         mqttclient.loop();
        }
        
     if (button_test == 1){  
         mqttclient.publish("/home/room1/switch1/sonoff-s20/relay","{\"status\":\"1\"}"); 
         delay(2000);
         mqttclient.publish("/home/room1/switch1/sonoff-s20/relay","{\"status\":\"0\"}"); 
         button_test=0;
        }
 
}

 

