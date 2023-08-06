// C++ code
//
void setup()
{
 pinMode(2, OUTPUT);
  Serial.begin(9600);
  Serial.println("LED STATUS:");
}

void loop()
{
  if(Serial.available())
  {
    char c = Serial.read();
    if (c=='1')
    {
      digitalWrite (2,HIGH);
    }
    if (c=='0')
    {
      digitalWrite (2,LOW);
    }
    Serial.println(c);
  }
}