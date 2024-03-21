#include "CapTempHum.h"

void CapTempHum::initCapt()
{
    //Permet d'initialiser le capteur
    pdht22->begin();
}

float CapTempHum::getTemp()
{
    //On obtient la valeur de la température du DHT22
    temp = pdht22->readTemperature();
    return temp;
}

float CapTempHum::getHum()
{
    //On obtient la valeur de l'humidité du DHT22
    hum = pdht22->readHumidity();
    return hum;
}

void CapTempHum::display()
{
    //On affiche la température et l'humidité de l'air ambiant   
    Serial.print("Humidite de l'air: ");
    Serial.print(hum);
    Serial.print("%");

    Serial.print("  |  ");
    
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print("°C");
    Serial.print("\n");
}

CapTempHum::CapTempHum(uint8_t pin, uint8_t type, uint8_t count ) //Constructeur
{
    //On crée un constructeur dynamique de type DHT
    pdht22 = new DHT(pin,type);

}

CapTempHum::~CapTempHum() //Destructeur
{
    //On libère de la mémoire
    delete pdht22;
}
