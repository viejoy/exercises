const int relayPin = 14;

void setup() {
Serial.begin(9600);
pinMode(relayPin, OUTPUT);
}

void loop() {
if(Serial.available()){
    String userin=Serial.readString();
    if(userin=="OFF"){
      digitalWrite(relayPin, LOW);
      Serial.println("Light is OFF");
    }
    else if(userin=="ON"){
      digitalWrite(relayPin, HIGH);
      Serial.println("Light is ON");
    }
  }

}
