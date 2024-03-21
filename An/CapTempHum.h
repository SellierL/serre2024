#include <DHT.h>
#include <Adafruit_Sensor.h>
#define DHT22_PIN  21 // ESP32 pin GPIO21 connecté au capteur DHT22

class CapTempHum
{
private:
    float temp;
    float hum;
    DHT *pdht22; //pointeur de la classe DHT22

public:
    void initCapt();
    float getTemp();
    float getHum();
    void display();
    CapTempHum(uint8_t pin, uint8_t type, uint8_t count = 6); //Constructeur
    ~CapTempHum(); //Destructeur
};