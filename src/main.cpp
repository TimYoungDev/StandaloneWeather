#include <Arduino.h>
#include <RTClib.h>
#include <LiquidCrystal.h>
#include <DHT.h>
#include "ezButton.h"

#include "LcdDateTime.h"
#include "LcdWeather.h"

#define DHT_INDOOR 13

#define LCD_RS 12
#define LCD_E  11
#define LCD_D4 7
#define LCD_D5 6
#define LCD_D6 5
#define LCD_D7 4

#define BUTTON_WEATHER 9


// Resources
DHT dhtIndoor(DHT_INDOOR, DHT22);
RTC_DS1307 rtc;
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
ezButton buttonDisplayWeather(BUTTON_WEATHER);

// Helpers
LcdDateTime lcdDateTime(&rtc, &lcd);
LcdWeather lcdWeather(&dhtIndoor, &lcd);


void setup() {
  Serial.begin(9600);

  dhtIndoor.begin();

  if (!rtc.begin()) {
    Serial.println("Unable to init RTC");
    while(1);
  }

  lcd.begin(16, 2);

  
  buttonDisplayWeather.setDebounceTime(50);
}

void loop() {
  buttonDisplayWeather.loop();

  if (buttonDisplayWeather.getState()) {
    lcdDateTime.displayDateTime();
  } else {
    lcdWeather.displayIndoorWeather();
  }

  delay(1000);
}
