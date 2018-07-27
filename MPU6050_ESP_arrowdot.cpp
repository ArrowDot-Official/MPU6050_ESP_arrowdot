#include "Arduino.h"
#include "MPU6050_ESP_arrowdot.h"

MPU6050_ESP::MPU6050_ESP() {

}
void MPU6050_ESP::begin() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(MPU_pwr);
  Wire.write(0);
  Wire.endTransmission(true);
}

void MPU6050_ESP::update() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true); // request
  accX = Wire.read() << 8 | Wire.read();
  accY = Wire.read() << 8 | Wire.read();
  accZ = Wire.read() << 8 | Wire.read();
}
