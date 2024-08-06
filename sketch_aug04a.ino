#include <stdio.h>
#include <LiquidCrystal.h>
#define sensor A1
#define motor 8
#define buzzer 9

float sensor_value;

LiquidCrystal lcd( 2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16,2);
  pinMode(A1, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  lcd.setCursor(3,0);
  lcd.print("Alcohol Detector");
  lcd.clear();
  Serial.begin(9600);
  delay(20000);
}

void loop() 
{
  int i;
  i = 390;
  sensor_value = analogRead(sensor);

    if(sensor_value>i)
    {
    lcd.setCursor(3,0);
    lcd.print("You Have Drunk");

    lcd.setCursor(2,1);
    lcd.print("Car wont start");
    
    Serial.println(sensor_value);
    Serial.println("You Have Drunk");
    
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(2000);
    lcd.clear();
  }
  else
  {
    lcd.setCursor(3,0);
    lcd.print("You are good to");
    lcd.setCursor(5,1);
    lcd.print("go");
    
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    
    Serial.println(sensor_value);
    Serial.println("good to go");
    delay(2000);
  }
 }
