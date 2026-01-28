#include <Arduino.h>
#include "sht30.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n--- TEST SHT30 ---");

  bool ok = sht30_begin(Wire, 22, 27, 100000, 0x44);

  if (ok) {
    Serial.println("✅ SHT30 trovato a 0x44");
  } else {
    Serial.println("❌ SHT30 NON trovato a 0x44");
    Serial.println("Provo 0x45...");
    ok = sht30_begin(Wire, 22, 27, 100000, 0x45);
    Serial.println(ok ? "✅ SHT30 trovato a 0x45" : "❌ SHT30 non risponde");
  }
}

void loop() {
  SHT30Reading r = sht30_read(Wire);

  if (r.ok) {
    Serial.print("🌡️ Temp: ");
    Serial.print(r.temperatureC, 2);
    Serial.print(" °C   💧 Umidità: ");
    Serial.print(r.humidityRH, 1);
    Serial.println(" %");
  } else {
    Serial.println("⚠️ Lettura fallita");
  }

  delay(2000);
}
