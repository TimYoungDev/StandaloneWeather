#include "DHT.h"
#include "LiquidCrystal.h"


class LcdWeather {
private:
    DHT* _dht;
    LiquidCrystal* _lcd;

public:
    LcdWeather(DHT* dht, LiquidCrystal* lcd) {
        _dht = dht;
        _lcd = lcd;
    }

    void displayIndoorWeather() {
        double t = _dht->readTemperature(true);
        double h = _dht->readHumidity();

        _lcd->clear();
        _lcd->setCursor(0,0);
        _lcd->print("Temp: ");
        _lcd->print(t);

        _lcd->setCursor(0, 1);
        _lcd->print("Humidity: ");
        _lcd->print(h);
    }
};
