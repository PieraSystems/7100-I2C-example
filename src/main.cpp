#include <Wire.h>
#include <Arduino.h>

#include <IpsI2C.h>

byte rcvData = 0;
byte rcvData2 = 0;

IpsSensor ips_sensor;

void setup()
{
  delay(3500);
  ips_sensor.begin();
  Serial.begin(115200);
  Serial.println("\nI2C Test");
}

void loop()
{
  ips_sensor.update();
  Serial.println(ips_sensor.getPC01());
  Serial.println(ips_sensor.getPM10());
  Serial.println(ips_sensor.getPM25());

  delay(1000);
}
