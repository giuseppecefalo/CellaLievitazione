#include <Arduino.h>
#include <Wire.h>

#include "sht30.h"        // definisce I2C_SDA e I2C_SCL
#include "PCF8574.h"

// Crea l’oggetto PCF8574 passandogli Wire
PCF8574 pcf(Wire);

// Configurazione relè
constexpr uint8_t RELAY1 = 0;
constexpr uint8_t RELAY2 = 1;
constexpr uint8_t RELAY3 = 2;
constexpr uint8_t RELAY4 = 3;
constexpr uint32_t RELAY_DELAY_MS = 1000;

void setup() {
  Serial.begin(115200);

  // Inizializza I2C con i pin definiti
  Wire.begin(SHT30_DEFAULT_SDA, SHT30_DEFAULT_SCL);
  Wire.setClock(100000);

  if (!pcf.begin()) {
    Serial.println("PCF8574 non trovato!");
    while (true) delay(1000);
  }
  Serial.println("PCF8574 pronto.");

  // Configura i pin dei relè come OUTPUT
  pcf.pinMode(RELAY1, OUTPUT);
  pcf.pinMode(RELAY2, OUTPUT);
  pcf.pinMode(RELAY3, OUTPUT);
  pcf.pinMode(RELAY4, OUTPUT);

  // Spegni tutti i relè
  pcf.digitalWrite(RELAY1, HIGH);
  pcf.digitalWrite(RELAY2, HIGH);
  pcf.digitalWrite(RELAY3, HIGH);
  pcf.digitalWrite(RELAY4, HIGH);

  delay(100);
}

void loop() {
  pcf.digitalWrite(RELAY1, LOW);
  delay(RELAY_DELAY_MS);
  pcf.digitalWrite(RELAY1, HIGH);

  pcf.digitalWrite(RELAY2, LOW);
  delay(RELAY_DELAY_MS);
  pcf.digitalWrite(RELAY2, HIGH);

  pcf.digitalWrite(RELAY3, LOW);
  delay(RELAY_DELAY_MS);
  pcf.digitalWrite(RELAY3, HIGH);

  pcf.digitalWrite(RELAY4, LOW);
  delay(RELAY_DELAY_MS);
  pcf.digitalWrite(RELAY4, HIGH);

  // ripeti
}
