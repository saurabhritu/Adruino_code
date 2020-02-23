#include<Servo.h>
#define ledPin 7
#define ledPin1 6
Servo servo;
int pos =0;
int state = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1,OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin1,LOW);
  servo.attach(5);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}
void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 // for led 0
 if (state == '0') {
  digitalWrite(ledPin, LOW); // Turn LED OFF
  Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == '1') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: ON");;
  state = 0;
 } 
   //for led 1
 if (state == '3') {
  digitalWrite(ledPin1, LOW); // Turn LED OFF
  Serial.println("LED1: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == '2') {
  digitalWrite(ledPin1, HIGH);
  Serial.println("LED1: ON");;
  state = 0;
 } 
 //for servo
 if (state == '4') {
  servo.write(90);
  delay(500);
  servo.write(0);
  Serial.println("turn 90"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == '5') {
  servo.write(180);
  delay(500);
  servo.write(0);
  Serial.println("turn 180");;
  state = 0;
 } 
}
