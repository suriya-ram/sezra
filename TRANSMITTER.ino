#include <SoftwareSerial.h>
SoftwareSerial LSerial1(2, 10);
SoftwareSerial LSerial2(3, 11);
SoftwareSerial LSerial3(4, 12); 
void setup() 
{
  delay(1000);
  Serial.begin(9600);
  Serial.println("Lifi Tx");
  LSerial1.begin(400);
  LSerial2.begin(400);
  LSerial3.begin(400);
}
     void loop() 
{
  LSerial1.print("A");
  LSerial2.print("B");
  LSerial3.print("C");
  delay(5000);  
}
