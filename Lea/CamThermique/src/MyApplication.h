#include <Arduino.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <WiFi.h>
#include <MLX90621.h>
#include <ESP_Mail_Client.h>
#include "ConnexionAPI.h"

#define NB_MEASURES 64
#define NUM_COLUMN 16
#define NUM_ROW 4
#define SMTP_SERVER "smtp.gmail.com"
#define SMTP_PORT 587
#define EMAIL_FROM "sellier.lea@gmail.com"
#define EMAIL_TO "lea.sellier@lyceeppr.fr"
#define EMAIL_SUBJECT "Alerte Stress Hydrique"
#define EMAIL_BODY "Alerte de stress hydrique dans la serre. Ceci est un message de test envoyé depuis ESP32."


class MyApplication
{
    private:
        MLX90621 sensorMLX; //creation de l'objet sensorMLx de type MLX90621
        ConnexionAPI connexion; //Creation de l'objet connexion de type ConnexionWebService
        float seuil=15.00; //Seuil pour le declanchement de l'alerte du stress hydrique (recup depuis API)
        float tabTemp[64]; // Tableau des mesures de température

    public:
        MyApplication();
        void initialisation();
        void setSeuil();
        void mapThermalDataToImage(const float* tableTemp, uint8_t* image);
        void alerteStressHydrique();
        void envoieImageAPI();
        void loopTest();

};
