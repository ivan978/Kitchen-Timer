#include "LiquidCrystal.h"
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int e1 = 0;
int e2 = 0;
int e3 = 0;
int hour = 0;
int minute = 0;

void setup() 
{
 pinMode(2, INPUT);
 pinMode(3, INPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(13, OUTPUT);
 lcd.begin(16, 2); 
 lcd.clear();
 lcd.print("Kitchen Timer");
 delay(3000);
}

void loop() 
{
lcd.clear();
lcd.print("Enter Hours");
delay(2000);

while(digitalRead(3) == LOW)
 {
   if(digitalRead(2) == HIGH)
   {
     delay(500);
    hour++;
   }
   lcd.clear();
   lcd.print(hour);
   delay(100);
 }
 
 lcd.clear();
 lcd.print("Enter Minutes");
 delay(2000);
 
 while(digitalRead(3) == LOW)
   {
   if(digitalRead(2) == HIGH)
   {
     delay(500);
    minute++;
   }
   lcd.clear();
   lcd.print(minute);
   delay(100);
 }
 
 delay(1000);
 e2 = minute;
 e3 = 0;
  
  for(e1 = hour; e1 >= 0; e1--)
 {
   for(e2; e2 >=0; e2--)
   {
     for(e3; e3 >= 0; e3--)
     {
       digitalWrite(4, HIGH);
       lcd.clear();
       lcd.print("   ");
       lcd.print("Time Left:");
       lcd.setCursor(0,1);
       lcd.print("    ");
       lcd.print(e1);
       lcd.print(":");
       lcd.print(e2);
       lcd.print(":");
       lcd.print(e3);
       delay(1000);
     }
 e3 = 59;
 }
 e2 = 59; 
 }
  
  while(true)
  {
   digitalWrite(4, LOW);
   digitalWrite(5, HIGH);
   lcd.clear();
   lcd.print("Time Finished!!");
   digitalWrite(13, HIGH);
   delay(500);
   digitalWrite(13, LOW);
   delay(500);
  }
}  
