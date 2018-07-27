#ifndef MPU6050_ESP_arrowdot_h
#define MPU6050_ESP_arrowdot_h

#include "Arduino.h"
#include <Wire.h>

#define MPU_addr    0x68
#define MPU_pwr     0x6b
#define Acc_Xout_H  0x3b

class MPU6050_ESP
{
  public:
    MPU6050_ESP();
    void begin();
    void update();
    int16_t getAccX(){ return accX; };
    int16_t getAccY(){ return accY; };
    int16_t getAccZ(){ return accZ; };
  private:
    int16_t accX,accY,accZ;
};

#endif
