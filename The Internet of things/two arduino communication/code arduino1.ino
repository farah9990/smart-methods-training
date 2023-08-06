// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode (4, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(4)== LOW)
  {
   Serial.print(1);
   delay(200);
  }
  else
  {
   Serial.print(0);
   delay(200);
  }
}