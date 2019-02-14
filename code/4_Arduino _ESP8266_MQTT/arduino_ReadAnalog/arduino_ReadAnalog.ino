void setup() {
  Serial.begin(9600);
}
void loop() { 
     String test = "Aa"; 
            test += analogRead(A0);
            test += "aA";  
     Serial.println(test);//Aa100aA
     delay(1000); 
}

 
 
