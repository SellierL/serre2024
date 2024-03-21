#include "CameraThermique.h"


//Constructeur sans parametre, conserve les valeurs par defaut
CameraThermique::CameraThermique()
{

    address=DEFAULT_ADDRESS;
    resolution_=DEFAULT_RESOLUTION;
    init();
}

//Constructeur avec un parametre modifiable, l'address i2c
CameraThermique::CameraThermique(int addressAdd)
{
    address = addressAdd;
    resolution_ = DEFAULT_RESOLUTION;
    //init();
}

//Constructeur avec deux parametres modifiable, l'address i2c et la resolution de l'image
CameraThermique::CameraThermique(int addressAdd, int resolutionAdd)
{
    address = addressAdd;
    resolution_ = resolutionAdd;
    //init();
}

//Initialise la camera thermique
void CameraThermique::init()
{

    Serial.println(F("trying to initialize sensor..."));
    sensor.setRefreshRate(RATE_8HZ);
    sensor.setResolution(RES_17bit);
    sensor.setEmissivity(1.0);
    sensor.initialize (); // start the thermo cam
    Serial.println(F("sensor initialized!"));
}

//Releve et affiche la temperature de chaque pixel pour une image
float CameraThermique::getTemperature()
{
    

}

//Calcul et affiche la moyenne des temperatures
void CameraThermique::averageTemperature()
{
    double sommeTemperatures = 0.0;
    int nombrePoints = 64; //16 x 4

    for(int y = 0; y < 4; y++) //les lignes de pixels
    {
        for(int x = 0; x < 16; x++) //les colonnes de pixels
        { 
            double tempAtXY = sensor.getTemperature(y + x * 4); // prend les températures au niveau des lignes et des colonnes
            sommeTemperatures += tempAtXY;
        }
    }
    double moyenne = sommeTemperatures / nombrePoints;
    Serial.print("La moyenne des points est : ");
    Serial.println(moyenne);
}


/*
//Creer l'echelle de couleur par rapport a une plage de temperature
Vec3b CameraThermique::mapTemperatureToColor(float temperature)
{
    //return Vec3b();
}
*/