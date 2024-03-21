#include <Arduino.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <WiFi.h>
#include <MLX90621.h>
#include "ConnexionAPI.h"

#define NB_MEASURES 64
#define NUM_COLUMN 16
#define NUM_ROW 4



class MyApplication
{
    private:
        MLX90621 sensorMLX; //creation de l'objet sensorMLx de type MLX90621
        ConnexionAPI connexion; //Creation de l'objet connexion de type ConnexionWebService
        float tabTemp[64]; // Tableau des mesures de température

    public:
        MyApplication();
        void initialisation();
        void loopTest();


};
