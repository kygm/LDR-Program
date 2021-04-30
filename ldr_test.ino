#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);
const int ldr = A0;
const int redLed = 2;
const int yelLed = 3;
const int grnLed = 4;


int ldrVal = 0;
String ldrString = "";
int ldrSum = 0;
double ldrAvg = 0.0;
void setup() 
{
  pinMode(redLed, 3);
  pinMode(yelLed, 4);
  pinMode(grnLed, 5);
  lcd.begin();
  Serial.begin(9600);
  lcd.backlight();
}

void loop() 
{
  lcd.clear();
  //Stroing photoresistor value in ldrVal
  ldrVal = analogRead(ldr);
  
  lcd.print("Avg Light lvl:");
  lcd.setCursor(0,1);
  lcd.blink();
  
  lcd.println(ldrVal);

  if(ldrVal < 150)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(yelLed, LOW);
    digitalWrite(grnLed, LOW);
  }
  if(ldrVal > 150 && ldrVal <= 300)
  {
    digitalWrite(redLed, LOW);
    digitalWrite(yelLed, HIGH);
    digitalWrite(grnLed, LOW);
  }
  if(ldrVal > 300)
  {
    digitalWrite(redLed, LOW);
    digitalWrite(yelLed, LOW);
    digitalWrite(grnLed, HIGH);
  }
  
  delay(500);
  
}
