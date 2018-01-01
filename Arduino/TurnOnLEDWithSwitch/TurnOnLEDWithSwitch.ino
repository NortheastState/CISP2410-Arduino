int switchPin = 8;
int ledPin = 13;
boolean ledState = false;

void setup() 
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  boolean switchPinRead = digitalRead(switchPin);
  if(switchPinRead == HIGH)
  {
    if(ledState == true)
    {
      digitalWrite(ledPin, LOW);
      ledState = false;  
    }
    else
    {
      digitalWrite(ledPin, HIGH);
      ledState = true;
    }
    delay(500); // (milliseconds) helps to response but slows down button reaction time
  }
}
