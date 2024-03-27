//ConnexionAPI.cpp

#include "ConnexionAPI.h"

ConnexionAPI::ConnexionAPI()
{

}

void ConnexionAPI::connexionWiFi()
{
    //Ssid et le password
    this->ssid = strdup("SNIR-S10");
    this->password = strdup("gpadid@s10");

    //Connexion WiFi
    WiFi.begin(ssid, password);

    Serial.print("Connexion en cours");
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("Connecté avec succès à : " + String(ssid));
    Serial.println("Adresse IP : " + WiFi.localIP().toString());    
}


void ConnexionAPI::connexionWiFi(const char* ssid_param, const char* password_param)
{

    // Libère la mémoire des anciennes valeurs
    free(ssid);
    free(password);

    this->ssid = strdup(ssid_param);//alloue dynamiquement de l'espace pour les chaines de caracteres et a copier les valeurs dans l'attribut ssid
    this->password = strdup(password_param);//alloue dynamiquement de l'espace pour les chaines de caracteres et a copier les valeurs dans l'attribut password

    WiFi.begin(ssid, password);

    Serial.print("Connexion en cours");
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("Connecté avec succès à : " + String(ssid));
    Serial.println("Adresse IP : " + WiFi.localIP().toString());

}



bool ConnexionAPI::authenticateL()// Renvoie true si l'authentification réussit, sinon false.
{
    //Test de la connexion WiFi avant l'envoie de la donnee
    if (!WiFi.isConnected()) 
    {
        Serial.println("Erreur : Pas de connexion Wi-Fi.");
        Serial.println("Tentative de reconnexion... ");
        connexionWiFi();
        return true;
    }

     // Logique d'authentification, récupération du token, etc.
        // Assure-toi de stocker le token de manière sécurisée (EEPROM, variables globales, etc.)
        // Utilise les fonctions HTTP appropriées pour effectuer l'authentification sur ton web service.
        return(1);

}


bool ConnexionAPI::authenticateC()// Renvoie true si l'authentification réussit, sinon false.
{
    //Test de la connexion WiFi avant l'envoie de la donnee
    if (!WiFi.isConnected()) 
    {
        Serial.println("Erreur : Pas de connexion Wi-Fi.");
        Serial.println("Tentative de reconnexion... ");
        connexionWiFi();
        return true;
    }
     // Logique d'authentification, récupération du token, etc.
        // Assure-toi de stocker le token de manière sécurisée (EEPROM, variables globales, etc.)
        // Utilise les fonctions HTTP appropriées pour effectuer l'authentification sur ton web service.
        return(1);

}


bool ConnexionAPI::authenticateA()// Renvoie true si l'authentification réussit, sinon false.
{
    //Test de la connexion WiFi avant l'envoie de la donnee
    if (!WiFi.isConnected()) 
    {
        Serial.println("Erreur : Pas de connexion Wi-Fi.");
        Serial.println("Tentative de reconnexion... ");
        connexionWiFi();
        return true;
    }
     // Logique d'authentification, récupération du token, etc.
        // Assure-toi de stocker le token de manière sécurisée (EEPROM, variables globales, etc.)
        // Utilise les fonctions HTTP appropriées pour effectuer l'authentification sur ton web service.
        return(1);

}


bool ConnexionAPI::sendData(const char* jsonData)
{
    //Test de la connexion WiFi avant l'envoie de la donnee
    if (!WiFi.isConnected()) 
    {
        Serial.println("Erreur : Pas de connexion Wi-Fi.");
        Serial.println("Tentative de reconnexion... ");
        connexionWiFi();
        return true;
    }
    //Test de l'authentification a l'API avant l'envoie de la donnee
    if (!authenticateL()) 
    {
        Serial.println("Erreur d'authentification.");
        return false;
    }

    

    HTTPClient http;
    http.begin(webServiceURL);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", "Bearer " + String(authToken));

    int httpCode = http.POST(jsonData);

    if (httpCode == HTTP_CODE_OK) 
    {
        Serial.println("Données envoyées avec succès !");
    } 
    else 
    {
        Serial.printf("Erreur HTTP lors de l'envoi des données : %d\n", httpCode);
    }

        http.end();
        return true;
}




