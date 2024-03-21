#include "MyApplication.h"


MyApplication::MyApplication()
{
    tabTemp[64];
}

void MyApplication::initialisation()
{    
    Serial.begin(115200); //vitesse de transmission serial

    Serial.println(F("trying to initialize sensor..."));
    sensorMLX.setRefreshRate(RATE_8HZ);
    sensorMLX.setResolution(RES_17bit);
    sensorMLX.setEmissivity(1.0);
    sensorMLX.initialize (); // start the thermo cam
    Serial.println(F("sensor initialized!"));

    connexion.connexionWiFi();
}


void MyApplication::loopTest()
{
    sensorMLX.measure(true); //Important ! Get NEW readings from the sensor
    float temperatures[64];
    for (int i=0; i<64; i++)
    {
        temperatures[i]=sensorMLX.getTemperature(i);
        Serial.print("Pixel: ");
        Serial.print(i);
        Serial.print(" / Temperature: ");
        Serial.println(temperatures[i]);
    }

    delay(10000);  // Attendre 10 secondes avant la prochaine lecture
}
