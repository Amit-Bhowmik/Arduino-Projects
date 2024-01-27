
int led[] = {9, 10, 11}; // Define an array to store the pin numbers of the LEDs
int data;

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT); // Set all LED pins as outputs
  }
}

void loop()
{
  while(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.println(data);
    if(data == 'A'){
      fadeOn(); 
    }
    if(data == 'B'){
      fadeOff(); 
    }
    if(data == 'C'){
      turnOnOffSequentially(); // Call function to turn on LEDs sequentially
    }
    if(data == 'D'){
      turnOffAll(); // Turn off all LEDs
    }
  }
}

void fadeOn() {
  for (int i = 0; i < 3; i++) {
      for (int brightness = 0; brightness <= 255; brightness++) {
        analogWrite(led[0], brightness); 
        delay(10); 
    }
  }

}

void fadeOff() {
  for (int i = 0; i < 3; i++) {
      for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(led[0], brightness);
      delay(10); 
    }
  }

}

void turnOnOffSequentially() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(led[i], HIGH); // Turn on one LED at a time
    delay(100);
    digitalWrite(led[i], LOW);
    delay(100); // Adjust delay between turning on LEDs here
  }
}

void turnOffAll() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(led[i], LOW);
    delay(100); // Turn off all LEDs
  }
}
