#ifndef SHT30_H
#define SHT30_H

#include <Arduino.h>
#include <Wire.h>

#define SHT30_DEFAULT_SDA   22
#define SHT30_DEFAULT_SCL   27
#define SHT30_DEFAULT_ADDR  0x44
#define SHT30_DEFAULT_FREQ  100000  // 100 kHz

typedef struct {
  float temperatureC;
  float humidityRH;
  bool ok;
} SHT30Reading;

bool sht30_begin(
  TwoWire &bus = Wire,
  uint8_t sda = SHT30_DEFAULT_SDA,
  uint8_t scl = SHT30_DEFAULT_SCL,
  uint32_t freq = SHT30_DEFAULT_FREQ,
  uint8_t addr = SHT30_DEFAULT_ADDR
);

SHT30Reading sht30_read(
  TwoWire &bus = Wire,
  uint8_t addr = SHT30_DEFAULT_ADDR
);

#endif
