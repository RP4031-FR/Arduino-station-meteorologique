#include <LiquidCrystal.h>
#include "DHT.h"

LiquidCrystal lcd(12, 11, 5, 4, 13, 3);

#define PinCapteur 2
#define Type DHT11

DHT dht(PinCapteur, Type);

void setup() {
  Serial.begin(9600);      // ← Activation du Serial Monitor
  lcd.begin(16, 2);
  dht.begin();

  Serial.println("Station meteo Arduino prête");
}

void loop() {
  delay(5000);

  float humidite = dht.readHumidity();
  float temperature = dht.readTemperature();

  // --- Affichage LCD ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp. = ");
  lcd.print(temperature);

  lcd.setCursor(0, 1);
  lcd.print("Humidite = ");
  lcd.print(humidite);

  // --- Affichage Serial Monitor ---
  Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidite : ");
  Serial.print(humidite);
  Serial.println(" %");

  Serial.println("----------------------");
}