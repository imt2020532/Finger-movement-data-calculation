

#include <Wire.h>
#include <QMC5883L.h>
#include <I2CMux.h>
#include<stdio.h>
QMC5883L compass;
#define I2CMux_ADDR 0x70
I2CMux mux(I2CMux_ADDR);

void setup() {
  
  Wire.begin();
  Serial.begin(38400);
  compass.init();

pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
}

void loop() {
  int x, y, z, i=1;
  mux.switchToBus(1);
  compass.read(&x, &y, &z);
  
  //Serial.println("for the chip number : ");
  Serial.println(1);
  Serial.print(",");
  //Serial.print("x: ");
  Serial.print(x);
  Serial.print(",");
  //Serial.print("    y: ");
  Serial.print(y);
  //Serial.print("    z: ");
  Serial.print(",");
  Serial.println(z);

  //delay(100);

  //digitalWrite(2,0);
  //digitalWrite(3,1);
  mux.switchToBus(2);
  
  compass.read(&x, &y, &z);
  //Serial.println("for the chip number : ");
  Serial.println(2);
  Serial.print(",");
  //Serial.print("x: ");
  Serial.print(x);
  //Serial.print("    y: ");
  Serial.print(",");
  Serial.print(y);
  //Serial.print("    z: ");
  Serial.print(",");
  Serial.println(z);

  //delay(100);

  //i = i + 1;
  //}
  //return 0;
}