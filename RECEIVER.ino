//#include <DFRobotDFPlayerMini.h>
#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h>
//SoftwareSerial GSerial(11,12); 
SoftwareSerial DFSerial(2,3); 
#include <LiquidCrystal.h>
LiquidCrystal lcd(4,5,6,7,8,9); 
int buzzer=13;
DFRobotDFPlayerMini myDFPlayer;
      unsigned long previousMillis=0;
char rec=0;
void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Navigation Sys.");
  lcd.setCursor(0, 1);
  lcd.print("using LiFi");
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  Serial.begin(400);
  //GSerial.begin(400);
  DFSerial.begin(9600);
  //Serial.println("Lifi Rx");
         delay(2000);
  if (!myDFPlayer.begin(DFSerial)) 
  {
      while(1)
      {
        digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzerLOW);delay(200); 
      }
  }
myDFPlayer.setTimeOut(500);
myDFPlayer.volume(30);  //Set volume value. From 0 to 30
myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
    myDFPlayer.playFolder(1,1);
    lcd.clear();
    previousMillis = millis();
}
      void loop()
{
      if(millis() - previousMillis > 5000)
  {
    rec = 0;
    lcd.clear();
  }
  if(Serial.available() != 0)
  {    
    rec = Serial.read();
    if(rec=='A')
    {
     digitalWrite(buzzer,HIGH);delay(100);digitalWrite(buzzer, LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Koturpuram Signal");
      lcd.setCursor(0, 1);
      lcd.print("R:CEG L:Adyar");
     myDFPlayer.playFolder(1,2);
      delay(3000);
      previousMillis = millis();
      rec = 0;
      lcd.clear();
    }
    if(rec=='B')
    {
      digitalWrite(buzzer, HIGH);delay(100);digitalWrite(buzzer, LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Chennai Ctrl.");
      lcd.setCursor(0, 1);
      lcd.print("R:GH Rd L:Park");
      myDFPlayer.playFolder(1,3);
      delay(3000);
      previousMillis = millis();
      rec = 0;
      lcd.clear();
    }
    if(rec=='C')
    {
      digitalWrite(buzzer, HIGH);delay(100);digitalWrite(buzzer, LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("P-LIBRARY");
      lcd.setCursor(0, 1);
      lcd.print("L:Hut R:Hotel");
      myDFPlayer.playFolder(1,4);
      delay(3000);
      previousMillis = millis();
      rec = 0;
      lcd.clear();
    }
  }
} 
