#include <LiquidCrystal.h>

// RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(8, 2, 10, 11, 12, 13);

const int ledPin3 = 3;
const int ledPin4 = 4;
const int ledPin5 = 5;
const int ledPin6 = 6;
const int ledPin7 = 7;
const int piezoPin = 9;
const int tmp36Pin = A0;
const int photoresistorPin = A1;
const int humiditySensorPin = A2;

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
int photoresistorValue = 0;
int humiditySensorValue = 0;
int humidityPercent = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  
  lcd.begin(16,2);
}

void loop() {
  float celsius = (analogRead(tmp36Pin) / 1024.0) * 500.0 - 50.0;
  int ledValue = int(celsius);
  
  photoresistorValue = analogRead(photoresistorPin);
  humiditySensorValue = analogRead(humiditySensorPin);
  humidityPercent = map(humiditySensorValue, sensorHigh, sensorLow, 0, 100);
  
  if (ledValue < 15){
    digitalWrite(ledPin7, LOW); 
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin5, LOW); 
    digitalWrite(ledPin4, LOW); 
    digitalWrite(ledPin3, HIGH);
  }else if (ledValue >= 15 && ledValue < 23){
    digitalWrite(ledPin7, LOW); 
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin5, LOW); 
    digitalWrite(ledPin4, HIGH); 
    digitalWrite(ledPin3, HIGH);
  }else if (ledValue >= 23 && ledValue < 28){
    digitalWrite(ledPin7, LOW); 
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin5, HIGH); 
    digitalWrite(ledPin4, HIGH); 
    digitalWrite(ledPin3, HIGH);
  }
  else if (ledValue >= 28 && ledValue < 33){
    digitalWrite(ledPin7, LOW); 
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin5, HIGH); 
    digitalWrite(ledPin4, HIGH); 
    digitalWrite(ledPin3, HIGH);
  }
  else{
    digitalWrite(ledPin7, HIGH); 
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin5, HIGH); 
    digitalWrite(ledPin4, HIGH); 
    digitalWrite(ledPin3, HIGH);
  }
  
  if (ledValue > 38) { // hőmérséklet küszöbértéke
    digitalWrite(piezoPin, HIGH);
    delay(500);
    digitalWrite(piezoPin, LOW);
    delay(500);
  }
  
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(humidityPercent);
  lcd.print(" %     ");
  
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(ledValue);
  lcd.print(" C  ");
  
  delay(4000); // várakozás 4 másodpercig
  int startTime = millis(); // elmentjük az indulási időt

  while (millis() - startTime < 4000) { // amíg nem telik el a 4 másodperc
    int photoresistorValue = analogRead(photoresistorPin);
    int mappedPhotoresistorValue = map(photoresistorValue, 0, 1023, 0, 255); // átalakítjuk a 0-1023-as értéket 0-255-ös skálára
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Weather:");
    if (mappedPhotoresistorValue < 85) {
      lcd.setCursor(0, 1);
      lcd.print("Cloudy");
    } else if (mappedPhotoresistorValue >= 85 && mappedPhotoresistorValue < 170) {
      lcd.setCursor(0, 1);
      lcd.print("Scattered clouds");
    } else {
      lcd.setCursor(0, 1);
      lcd.print("Sunny");
    }
    delay(500); // várakozás fél másodpercig, hogy ne frissüljön túl gyorsan
  }
  lcd.clear(); // töröljük a kijelzőt
}
