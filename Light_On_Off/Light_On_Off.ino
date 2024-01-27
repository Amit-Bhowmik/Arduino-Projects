int led = 13;
int data;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  while(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.println(data);
    if(data == 'A'){
      digitalWrite(13, HIGH);
    }
    if(data == 'B'){
      digitalWrite(13, LOW);
    }
  }
}