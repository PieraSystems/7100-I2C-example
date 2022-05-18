#pragma once


union bytesToPM
{
  float f;
  unsigned char byte[4];
};

class IpsSensor
{
public:
    unsigned long pc_values[7] = {0, 0, 0, 0, 0, 0, 0};
    float pm_values[7] = {0, 0, 0, 0, 0, 0, 0};
    void begin(int sda = 21, int scl = 22);
    void update();
    unsigned long *getPC();
    unsigned long getPC01();
    unsigned long getPC03();
    unsigned long getPC05();
    unsigned long getPC10();
    unsigned long getPC25();
    unsigned long getPC50();
    unsigned long getPC100();
    float *getPM();
    float getPM01();
    float getPM03();
    float getPM05();
    float getPM10();
    float getPM25();
    float getPM50();
    float getPM100();
    int getVref();
    int getStatus();
    int getDataUnit();
    void getSerial(uint8_t* message);
    void getVersion(uint8_t* message);
    unsigned long getCleaningInterval();
    bool setCleaningInterval(unsigned long interval);
    bool setFan(bool);
    bool setPSM(bool);
    bool setDataUnit(int unit);
    void read_i2c(unsigned char, int, uint8_t[], bool checksum = false);
    bool write_i2c(unsigned char, unsigned char);
    uint16_t get_checksum(uint8_t *byte, int);
    void setDebug(bool);
};