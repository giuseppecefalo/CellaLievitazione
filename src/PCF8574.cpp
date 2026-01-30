#include "PCF8574.h"

PCF8574::PCF8574(TwoWire& wire)
: _wire(&wire), _port(0xFF) {}

bool PCF8574::begin(uint32_t i2cClockHz) {
  _wire->setClock(i2cClockHz);

  // Stato iniziale: tutti HIGH (input / weak-high)
  _port = 0xFF;

  if (!probe()) return false;
  return writePort(_port);
}

bool PCF8574::probe() const {
  _wire->beginTransmission(PCF8574_I2C_ADDRESS);
  return (_wire->endTransmission() == 0);
}

void PCF8574::pinMode(uint8_t pin, uint8_t mode) {
  if (pin > 7) return;

  if (mode == INPUT) {
    _port |= (1U << pin);
    writePort(_port);
  }
}

void PCF8574::digitalWrite(uint8_t pin, uint8_t val) {
  if (pin > 7) return;

  if (val == HIGH) _port |= (1U << pin);
  else             _port &= ~(1U << pin);

  writePort(_port);
}

int PCF8574::digitalRead(uint8_t pin) {
  if (pin > 7) return LOW;

  uint8_t v;
  if (!readPort(v)) return LOW;
  return (v & (1U << pin)) ? HIGH : LOW;
}

bool PCF8574::writePort(uint8_t value) {
  _port = value;
  _wire->beginTransmission(PCF8574_I2C_ADDRESS);
  _wire->write(_port);
  return (_wire->endTransmission() == 0);
}

bool PCF8574::readPort(uint8_t &value) {
  if (_wire->requestFrom((int)PCF8574_I2C_ADDRESS, 1) != 1) return false;
  value = _wire->read();
  _port = value;
  return true;
}

bool PCF8574::updateMasked(uint8_t mask, uint8_t values) {
  uint8_t newPort = (_port & ~mask) | (values & mask);
  return writePort(newPort);
}
