int switchPin = 8;
int ledPin = 11; // PWM pin
int ledLevel = 0;
boolean ledState = true; //true for up, false for down

void setup() 
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
                          
void loop() 
{
  boolean switchPinRead = digitalRead(switchPin);
  if(switchPinRead == HIGH)
  {
    if(ledState == true)
    {
      ledLevel = ledLevel + 51; //255 is divisible by 51, but could be any integer
      analogWrite(ledPin, ledLevel);
      if(ledLevel == 255)
      {
        ledState = false; 
      }  
    }
    else
    {
      ledLevel = ledLevel - 51;
      analogWrite(ledPin, ledLevel);
      if(ledLevel == 0)
      {
        ledState = true; 
      }
    }
    delay(100); // (milliseconds) helps to response but slows down button reaction time
  }
}
