const int trigPin =2;
const int echoPin = 4;
const int motorPin =9;
void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop() {
long duration, inches;
pinMode(trigPin, OUTPUT);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
inches = microsecondsToInches(duration);
Serial.print(inches);
Serial.print(" in.");
delay(100);?

if (inches <= 20){
  
  digitalWrite(motorPin,HIGH);
  }
  else{
    digitalWrite(motorPin, LOW);
  }
}

long microsecondsToInches(long microseconds) {

  return microseconds / 74 / 2;
}

