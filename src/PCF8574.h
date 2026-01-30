#pragma once
#include <Arduino.h>
#include <Wire.h>

/* ===========================
   CONFIGURAZIONE PCF8574
   =========================== */
constexpr uint8_t PCF8574_I2C_ADDRESS = 0x20;

/**
 * PCF8574 - I2C 8-bit IO expander
 */
class PCF8574 {
public:
  explicit PCF8574(TwoWire& wire = Wire);

  // Wire già inizializzato (SDA/SCL in sth.h)
  bool begin(uint32_t i2cClockHz = 100000);
  bool probe() const;

  void pinMode(uint8_t pin, uint8_t mode);
  void digitalWrite(uint8_t pin, uint8_t val);
  int  digitalRead(uint8_t pin);

  bool writePort(uint8_t value);
  bool readPort(uint8_t &value);
  bool updateMasked(uint8_t mask, uint8_t values);

  uint8_t cachedPort() const { return _port; }

private:
  TwoWire* _wire;
  uint8_t  _port;
};
