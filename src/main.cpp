#include <Wire.h>
#include <Arduino.h>

#include <IpsI2C.h>

IpsSensor ips_sensor;

void setup()
{
  delay(3500);
  // Initiate I2C connection SDA 21, SCL 22 by default
  // Set different pins by using:
  // ips_sensor.begin(SDA_PIN, SCL_PIN)
  ips_sensor.begin();

  // Initiate USB serial at 115200 baud
  Serial.begin(115200);
  Serial.println("\nI2C Test");
}

void loop()
{
  // Get new IPS sensor readings
  // Not meant to run more than once per second
  ips_sensor.update();

  // Print PC0.1 via USB serial
  Serial.println(ips_sensor.getPC01());

  // Print PM1.0 via USB serial
  Serial.println(ips_sensor.getPM10());

  // Print PM2.5 via USB serial
  Serial.println(ips_sensor.getPM25());

  delay(1000);
}
