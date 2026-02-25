#include <LiquidCrystal.h>
#include "DHT.h"
LiquidCrystal lcd(12, 11, 5, 4, 13, 3);
#define PinCapteur 2
#define Type DHT11

DHT dht(PinCapteur, Type);

void setup()
[
lcd.begin(16, 2);
dht.begin();
]

void loop()
[
delay(5000);
float humidite = dht.readHumidity();
float temperature = dht.
read Temperature();
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Temp. = ");
lcd.print(temperature);
lcd.setCursor(0, 1);
lcd.print("Humidite = ");
lcd.print(humidite);
]