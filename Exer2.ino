const int motorPin =9;
int maxspeed=255;
int midspeed=200;
int slowspeed=180;;

void setup() {
Serial.begin(9600);
pinMode(motorPin, OUTPUT);

}

void loop() {
  if(Serial.available()){
    char userin=Serial.read();
    if(userin=='3'){
      analogWrite(motorPin, maxspeed);
      Serial.println("maxspeed");
    }
    else if(userin=='2'){
      analogWrite(motorPin, midspeed);
      Serial.println("midspeed");
    }
    else if(userin=='1'){
      analogWrite(motorPin, slowspeed); 
      Serial.println("slowspeed");
    }
    else if(userin=='0'){
      analogWrite(motorPin, 0);
      Serial.println("off");  
    }
   }
}
      

