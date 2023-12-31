#include <Wire.h>  // Library for I2C communication
#include <DS3231.h>
#include <LiquidCrystal_I2C.h>  // Library for LCD

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

DS3231 myRTC;
bool century = false;
bool h12Flag;
bool pmFlag;

byte year = 23;
byte month = 10;
byte date = 30;
byte dOW = 6;
byte hour = 23;
byte minute = 45;
byte second = 0;

void setup() {
  Serial.begin(57600);  // Set serial port speed
  Wire.begin();         // Start the I2C
  lcd.init();
  lcd.backlight();
  myRTC.setClockMode(false);  // set to 24h
  myRTC.setYear(year);
  myRTC.setMonth(month);
  myRTC.setDate(date);
  myRTC.setDoW(dOW);
  myRTC.setHour(hour);
  myRTC.setMinute(minute);
  myRTC.setSecond(second);

  Serial.print('Time and date set');
  lcd.setCursor(0, 0);
  lcd.print("Real Time Clock");
  delay(3000);
  lcd.clear();
}

void loop() {
  Serial.print(myRTC.getYear());
  Serial.print('/');
  Serial.print(myRTC.getMonth(century));
  Serial.print('/');
  Serial.print(myRTC.getDate());
  Serial.print(' ');
  Serial.print(myRTC.getHour(h12Flag, pmFlag));
  Serial.print(':');
  Serial.print(myRTC.getMinute());
  Serial.print(':');
  Serial.print(myRTC.getSecond());
  Serial.println();


  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  lcd.setCursor(0, 1);
  lcd.print("Time: ");

  lcd.setCursor(6, 0);
  lcd.print(myRTC.getYear());
  lcd.print(":");
  lcd.print(myRTC.getMonth(century));
  lcd.print(":");
  lcd.print(myRTC.getDate());

  lcd.setCursor(6, 1);
  lcd.print(myRTC.getHour(h12Flag, pmFlag));
  lcd.print(":");
  lcd.print(myRTC.getMinute());
  lcd.print(":");
  lcd.print(myRTC.getSecond());
  delay(1000);
  lcd.clear();
}