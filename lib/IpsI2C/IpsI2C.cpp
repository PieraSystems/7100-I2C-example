#include "Arduino.h"
#include "Wire.h"

#include "IpsI2C.h"

void IpsSensor::begin(int sda, int scl)
{
  Wire.begin(sda, scl);
}

void IpsSensor::update()
{
  // Read PC data
  std::vector<int> pc_raw_values = this->read_i2c(0x11, 29, true);

  // Assemble PC values (unsigned long) from 4 bytes via bitwise
  this->pc_values[0] = pc_raw_values[3] | (pc_raw_values[2] << 8) | (pc_raw_values[1] << 16) | (pc_raw_values[0] << 24);
  this->pc_values[1] = pc_raw_values[7] | (pc_raw_values[6] << 8) | (pc_raw_values[5] << 16) | (pc_raw_values[4] << 24);
  this->pc_values[2] = pc_raw_values[11] | (pc_raw_values[10] << 8) | (pc_raw_values[9] << 16) | (pc_raw_values[8] << 24);
  this->pc_values[3] = pc_raw_values[15] | (pc_raw_values[14] << 8) | (pc_raw_values[13] << 16) | (pc_raw_values[12] << 24);
  this->pc_values[4] = pc_raw_values[19] | (pc_raw_values[18] << 8) | (pc_raw_values[17] << 16) | (pc_raw_values[16] << 24);
  this->pc_values[5] = pc_raw_values[23] | (pc_raw_values[22] << 8) | (pc_raw_values[21] << 16) | (pc_raw_values[20] << 24);
  this->pc_values[6] = pc_raw_values[27] | (pc_raw_values[26] << 8) | (pc_raw_values[25] << 16) | (pc_raw_values[24] << 24);

  // Read PM data
  std::vector<int> pm_raw_values = this->read_i2c(0x12, 29, true);
  
  // Assemble PM values (float) from 4 bytes via union
  for (size_t i = 0; i < 7; ++i)
  {
    bytesToPM b;
    for (size_t j = 0; j < 4; ++j)
    {
      b.byte[j] = pm_raw_values[j + (i * 4)];
    }
    this->pm_values[i] = b.f;
  }

  // Debug raw bytes

  // Serial.print("[ ");
  // for (auto &single_byte : pc_raw_values)
  // {
  //   Serial.print(single_byte);
  //   Serial.print(" ");
  // }
  // Serial.print("]\n");
}

uint8_t IpsSensor::get_checksum(int *byte, int len)
{
  int i;
  uint8_t crc = 0;
  for (i = 0; i < len; i++)
  {
    crc ^= byte[i];
  }
  return crc;
}

std::vector<int> IpsSensor::read_i2c(unsigned char command, int reply_size, bool checksum)
{
  bool checksum_pass = false;
  std::vector<int> received_bytes;
  while (!checksum_pass)
  {
    received_bytes.clear();
    Wire.beginTransmission(0x4B);
    Wire.write(command);
    Wire.endTransmission();
    Wire.requestFrom(0x4B, reply_size);
    for (int n = 1; n <= reply_size; n++)
    {
      received_bytes.push_back(Wire.read());
    }
    if (!checksum)
    {
      break;
    }
    uint8_t message_check = this->get_checksum(received_bytes.data(), 28);
    if (message_check == received_bytes[received_bytes.size() - 1])
    {
      checksum_pass = true;
    }
    else
    {
      // Checksum failed;
      //Serial.println("Checksum Failed.");
      delay(10);
    }
  }
  return received_bytes;
}

unsigned long *IpsSensor::getPC()
{
  return this->pc_values;
};

unsigned long IpsSensor::getPC01()
{
  return this->pc_values[0];
};
unsigned long IpsSensor::getPC03()
{
  return this->pc_values[1];
};
unsigned long IpsSensor::getPC05()
{
  return this->pc_values[2];
};
unsigned long IpsSensor::getPC10()
{
  return this->pc_values[3];
};
unsigned long IpsSensor::getPC25()
{
  return this->pc_values[4];
};
unsigned long IpsSensor::getPC50()
{
  return this->pc_values[5];
};
unsigned long IpsSensor::getPC100()
{
  return this->pc_values[6];
};

float *IpsSensor::getPM()
{
  return this->pm_values;
};

float IpsSensor::getPM01()
{
  return this->pm_values[0];
}
float IpsSensor::getPM03()
{
  return this->pm_values[1];
}
float IpsSensor::getPM05()
{
  return this->pm_values[2];
}
float IpsSensor::getPM10()
{
  return this->pm_values[3];
}
float IpsSensor::getPM25()
{
  return this->pm_values[4];
}
float IpsSensor::getPM50()
{
  return this->pm_values[5];
}
float IpsSensor::getPM100()
{
  return this->pm_values[6];
}

// int IpsSensor::getVref()
// {
//   // Read Vref
//   std::vector<int> message = this->read_i2c(0x69, 2);
//   unsigned short int x;
//   x = message[1] | (message[0] << 8);
//   Serial.println(x);
// }