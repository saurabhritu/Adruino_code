int LED = 13; // Use the onboard Uno LED
int obstaclePin = 7;  // This is our input pin
int hasObstacle = LOW;  // LOW MEANS NO OBSTACLE
int state =0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(obstaclePin, INPUT);
  Serial.begin(38400);  
}
void loop() {
  hasObstacle = digitalRead(obstaclePin); //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
   if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 if(state = '1'){
  digitalRead(hasObstacle);
  
  if (hasObstacle == LOW) //LOW means Path is clear, off the led.
  {
    Serial.println("Path is clear");
    digitalWrite(LED, LOW);//off the 13th Port LED
  }
  else
  {
    Serial.println("Stop something is ahead!!");
    digitalWrite(LED, HIGH);// iluminates the 13th led
  }
 }
 delay(1000);
 
}

