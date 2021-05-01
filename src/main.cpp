#include <Wire.h>
#include <Arduino.h>

#include <IpsI2C.h>

IpsSensor ips_sensor;

int success_count;
int fail_count;

void setup()
{
  // Wait on IPS bootloader
  delay(3500);

  // Initiate I2C connection SDA 21, SCL 22 by default
  // Set different pins by using:
  // ips_sensor.begin(SDA_PIN, SCL_PIN)
  ips_sensor.begin();
  //ips_sensor.begin();

  // Initiate USB serial at 115200 baud
  Serial.begin(115200);
  Serial.println("\nI2C Test");
}

void loop()
{
  // Get new IPS sensor readings
  // Not meant to run more than once per second
  ips_sensor.update();

  //Enable debugging
  // ips_sensor.setDebug(true);

  // Print PC0.1 via USB serial
  // Serial.println(ips_sensor.getPC01());

  // Print PM1.0 via USB serial
  Serial.print("PM1.0: ");
  Serial.print(ips_sensor.getPM10());
  Serial.print("\n");

  // Print PM2.5 via USB serial
  Serial.print("PM2.5: ");
  Serial.print(ips_sensor.getPM25());
  Serial.print("\n");

  // Print PM10 via USB serial
  Serial.print("PM10: ");
  Serial.print(ips_sensor.getPM100());
  Serial.print("\n");

  // Print sensor status
  // int status = ips_sensor.getStatus();
  // Serial.println(status);

  // Print Vref value
  // int vref = ips_sensor.getVref();
  // Serial.println(vref);

  // Testing I2C accuracy
  // if (vref == 1800) {
  //   success_count++;
  // } else {
  //   fail_count++;
  // }
  // if (status == 1) {
  //   success_count++;
  // } else {
  //   fail_count++;
  // }
  // Serial.print("Success_count: ");
  // Serial.print(success_count);
  // Serial.print(" Fail_count: ");
  // Serial.print(fail_count);
  // Serial.print("\n");

  delay(1000);
}
