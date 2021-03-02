#include <Wire.h>
#include <Arduino.h>

#include <IpsI2C.h>

byte rcvData = 0;
byte rcvData2 = 0;

IpsSensor sensor;

void setup()
{
  delay(3500);
  sensor.begin();
  Serial.begin(115200);
  Serial.println("\nI2C Test");
}

void loop()
{
  sensor.update();
  Serial.println(sensor.getPC01());
  Serial.println(sensor.getPM10());
  Serial.println(sensor.getPM25());

  delay(1000);
}
