# 7100-I2C-example

### Important Update: Starting with firmware version 1.86, checksums are now two bytes long. For firmware versions 1.83 and below, [refer to this code](https://github.com/PieraSystems/7100-I2C-example/archive/refs/tags/1.83.zip).

## Parts required
* [Piera Systems IPS-7100](https://www.pierasystems.com/products/)
* [ESP32 devkit](https://www.digikey.com/en/products/detail/espressif-systems/ESP32-DEVKITC-32E/12091810)
* [5 pin 1.50mm connector](https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/648005113322/2508649?s=N4IgTCBcDaIGwBYAcAGFBWAjJgzDsEAugL5A)
* [Crimped wires (these snap into connector)](https://www.digikey.com/en/products/detail/jst-sales-america-inc/ASZHSZH28K305/6009456?s=N4IgTCBcDaICwFYEFoDMAGAHO5A5AIiALoC%2BQA)
* USB to micro USB cord (power/communication for ESP32)

## Instructions
1. Snap crimped wires into 5 pin connector to make a plug for the 7100.
1. Attach 7100 to ESP32 devkit accordingly:
    1. **VDD** on 7100 to **5V** on ESP32
    1. **SDA** on 7100 to **Pin 21** on ESP32
    1. **SCL** on 7100 to **Pin 22** on ESP32
    1. **SEL** on 7100 to **GND** on ESP32
    1. **GND** on 7100 to **GND** on ESP32
1. Copy GitHub files and load code into VSCode (*must have Platform.io extension*).
1. Flash ESP32 with code.
1. Open up serial terminal (baud rate 115200) to view data.