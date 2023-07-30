#include <Servo.h>
Servo myservo; // Servo object creation
int pos;
void setup()
{
  myservo.attach(8);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop()
{
  for (pos = 0; pos <= 180; pos++)
  {
    myservo.write(pos);
    delay(15);
    if(pos == 70)
    {
      digitalWrite(4, HIGH);
        delay(250);
    }
    else{
      digitalWrite(4, LOW);
    }
  }
  for (pos = 180; pos >= 0; pos--)
  {
    myservo.write(pos);
    delay(15);
    if(pos == 70)
    {
      digitalWrite(4, HIGH);
        delay(250);
    }
    else
    {
      digitalWrite(4, LOW);
    }
  }
 
}