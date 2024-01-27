
int led = 9; 
int data;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
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
      digitalWrite(9, HIGH); 
    }
    if(data == 'D'){
      digitalWrite(9, LOW); 
    }
  }
}

void fadeOn() {
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(led, brightness); 
    delay(10); 
  }
}

void fadeOff() {
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(led, brightness);

    delay(10); 
  }
}

