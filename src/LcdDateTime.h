#include "Arduino.h"
#include "RTClib.h"
#include "LiquidCrystal.h"


class LcdDateTime {
private:
    RTC_DS1307* _rtc;
    LiquidCrystal* _lcd;

public:
    LcdDateTime(RTC_DS1307* rtc, LiquidCrystal* lcd) {
        _rtc = rtc;
        _lcd = lcd;
    }

    void displayDateTime() {
    DateTime now = _rtc->now();
    String date = formatDate(now);
    String time = formatTime(now);

    _lcd->clear();
    _lcd->setCursor(0,0);
    _lcd->print(date);
    _lcd->setCursor(0, 1);
    _lcd->print(time);
    }

private:
    String formatDate(DateTime now) {
    String monthName;
    switch (now.month()) {
        case 1: monthName = "January"; break;
        case 2: monthName = "February"; break;
        case 3: monthName = "March"; break;
        case 4: monthName = "April"; break;
        case 5: monthName = "May"; break;
        case 6: monthName = "June"; break;
        case 7: monthName = "July"; break;
        case 8: monthName = "August"; break;
        case 9: monthName = "September"; break;
        case 10: monthName = "October"; break;
        case 11: monthName = "November"; break;
        case 12: monthName = "December"; break;
    }

    char buffer[20];
    sprintf(buffer, "%s, %2.2d %4.4d", monthName.c_str(), now.day(), now.year());
    return String(buffer);
    }

    String formatTime(DateTime now) {
    char buffer[20];
    sprintf(buffer, "%2.2d:%2.2d:%2.2d", now.hour(), now.minute(), now.second());
    return String(buffer);
    }

};
