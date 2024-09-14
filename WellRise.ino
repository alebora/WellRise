#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    const int colorR = 0;
    const int colorG = 0;
    const int colorB = 230;

    lcd.setRGB(colorR, colorG, colorB);
    lcd.print("hello, world!");

}


void loop() {
  // put your main code here, to run repeatedly:

}


#include <Arduino.h>
#include <Grove_LCD_RGB_Backlight_Extension.hpp>
#include <Grove_RTC_DS1307_Extension.hpp>
#include <Grove_RTC_DS1307_TimeLibSyncProvider.hpp>
#include <Time_Extension.hpp>

// set up the LCD's number of columns and rows
GroveLcdRgbBacklight rgbLcd(16, 2);
ColorSlider lcdSlider(Colors::Orange, Colors::Magenta);

// define DS1307 RTC clock
GroveRtcDs1307 ds1307Clock;

// define Time_Extension wrapper for DS1307 RTC clock
TimeExtension timeObj;

void setup() {

	Serial.begin(9600);

	// begin DS1307 real-time-clock
	ds1307Clock.begin();

	// synchronize Time library with DS1307 real-time-clock
	GroveRtcDs1307TimeLibSyncProvider::initialize(&ds1307Clock);

	rgbLcd.initialize();
}

// returns values from 0-3
uint8_t getCol() {

	time_t nowTime = timeObj.getNow();
	tmElements_t timeLibTimeStruct;

	// TimeLib::breakTime
	::breakTime(nowTime, timeLibTimeStruct);

	uint8_t col = timeLibTimeStruct.Second / 15;
	return col;
}

void printOnLine(uint8_t col, uint8_t row, const String &text) {
	rgbLcd.setCursor(0, row);
	rgbLcd.print("   "); // erase first columns, for when moving to the right
	rgbLcd.setCursor(col, row);
	rgbLcd.print(text);
	rgbLcd.print("   "); // erase last columns, for when moving to the left
}

void loop() {

	uint8_t col = getCol();
	printOnLine(col, 0, timeObj.getDateString());
	printOnLine(col, 1, timeObj.getTimeString());

	Serial.print("TimeLib: ");
	Serial.println(timeObj.getDateTimeString());
	Serial.print("Column: ");
	Serial.println(col);
	Serial.println();

	// wait 300 ms until we continue (above) with printing date/time.
	// during the wait, we continue to "color-slide" every 50 ms.
	lcdSlider.delayAndSlide(rgbLcd, 300, 50);
}

