#include "sht30.h"

static uint8_t sht30_crc8(const uint8_t *data, int len) {
  uint8_t crc = 0xFF;
  for (int i = 0; i < len; i++) {
    crc ^= data[i];
    for (int b = 0; b < 8; b++) {
      crc = (crc & 0x80) ? (uint8_t)((crc << 1) ^ 0x31) : (uint8_t)(crc << 1);
    }
  }
  return crc;
}

bool sht30_begin(TwoWire &bus, uint8_t sda, uint8_t scl, uint32_t freq, uint8_t addr) {
  bus.begin(sda, scl);
  bus.setClock(freq);
  bus.setTimeout(50);              // utile su ESP32 (evita blocchi)

  // ping
  bus.beginTransmission(addr);
  uint8_t err = bus.endTransmission();

  // pulizia buffer eventuale
  while (bus.available()) (void)bus.read();

  return (err == 0);
}

static bool sht30_read_once(TwoWire &bus, uint8_t addr, uint8_t buf[6]) {
  // comando misura: high repeatability, NO clock stretching
  bus.beginTransmission(addr);
  bus.write(0x24);
  bus.write(0x00);
  if (bus.endTransmission() != 0) return false;

  delay(30); // più margine rispetto a 15ms

  uint8_t n = bus.requestFrom((int)addr, 6);
  if (n != 6) return false;

  // aspetta che arrivino davvero tutti i byte
  uint32_t t0 = millis();
  while (bus.available() < 6 && (millis() - t0) < 20) {
    delay(1);
  }
  if (bus.available() < 6) return false;

  for (int i = 0; i < 6; i++) buf[i] = bus.read();
  return true;
}

SHT30Reading sht30_read(TwoWire &bus, uint8_t addr) {
  SHT30Reading r{NAN, NAN, false};
  uint8_t buf[6];

  // retry 3 volte (stabilizza tantissimo su breadboard / carico CPU)
  for (int attempt = 0; attempt < 3; attempt++) {
    while (bus.available()) (void)bus.read();

    if (!sht30_read_once(bus, addr, buf)) {
      delay(5);
      continue;
    }

    if (sht30_crc8(buf, 2) != buf[2]) { delay(5); continue; }
    if (sht30_crc8(buf + 3, 2) != buf[5]) { delay(5); continue; }

    uint16_t rawT = ((uint16_t)buf[0] << 8) | buf[1];
    uint16_t rawH = ((uint16_t)buf[3] << 8) | buf[4];

    r.temperatureC = -45.0f + 175.0f * ((float)rawT / 65535.0f);
    r.humidityRH   = 100.0f  * ((float)rawH / 65535.0f);
    r.ok = true;
    return r;
  }

  return r;
}
