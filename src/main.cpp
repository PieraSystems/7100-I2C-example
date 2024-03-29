#include <Wire.h>
#include <Arduino.h>

#include <IpsI2C.h>

IpsSensor ips_sensor;

int success_count;
int fail_count;
int last = true;

void setup()
{
  // Initiate USB serial at 115200 baud
  Serial.begin(115200);
  Serial.println("\nI2C Test");

  // Wait on IPS boot
  delay(5500);

  // Enable debugging
  // ips_sensor.setDebug(true);

  // Initiate I2C connection SDA 21, SCL 22 by default
  // Set different pins by using:
  // ips_sensor.begin(SDA_PIN, SCL_PIN)
  ips_sensor.begin(21, 22);
  
}

void loop()
{
  // Get new IPS sensor readings
  // Not meant to run more than once per second
  ips_sensor.update();

  Serial.print("PM2.5: ");
  Serial.print(ips_sensor.getPM25());
  Serial.print("\n");

  Serial.print("PC1.0: ");
  Serial.print(ips_sensor.getPC10());
  Serial.print("\n");

  // Print event status
  // Serial.print("Event status: ");
  // Serial.print(ips_sensor.getEventStatus());
  // Serial.print("\n");

  // Print sensor status
  // int status = ips_sensor.getStatus();
  // Serial.println(status);

  // Print data unit
  // int unit = ips_sensor.getDataUnit();
  // Serial.println("Data unit:");
  // Serial.println(unit);

  // Serial.print("Entering power saving mode...\n");
  // ips_sensor.setPSM(true);
  // delay(1000);

  // Serial.print("Leaving power saving mode...\n");
  // ips_sensor.setPSM(false);
  // delay(1000);
  
  // Serial.print("Serial #: ");
  // uint8_t serial[19];
  // ips_sensor.getSerial(serial);
  // Serial.print((char*) serial);
  // Serial.print("\n");

  // Serial.print("Version #: ");
  // uint8_t version[20];
  // ips_sensor.getVersion(version);
  // Serial.print((char*) version);
  // Serial.print("\n");

  // ips_sensor.setDataUnit(0);

  // Serial.print("Data unit: ");
  // Serial.print(ips_sensor.getDataUnit());
  // Serial.print("\n");

  // ips_sensor.setCleaningInterval(604800);
  // delay(500);
  // ips_sensor.setDataUnit(0);
  
  // Serial.print("Cleaning interval: ");
  // Serial.print(ips_sensor.getCleaningInterval());
  // Serial.print("\n");

  // Print sensor status
  // int status = ips_sensor.getStatus();
  // Serial.println("Status:");
  // Serial.println(status);

  // Print Vref value
  // int vref = ips_sensor.getVref();
  // Serial.print("Vref: ");
  // Serial.println(vref);
  // Serial.print("\n");

  delay(1000);
}
