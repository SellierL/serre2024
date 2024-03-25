//ConnexionAPI.h

#include <HTTPClient.h>
#include <WiFi.h>

#define DEFAULT_API_URL "http://172.18.10.42:8000/data/temp"
#define DEFAULT_AUTHENTIFICATON_TOKEN "Authentification"

class ConnexionAPI
{

    private:
        char* ssid;
        char* password;
        char* webServiceURL;
        char* authToken;

    public:
        ConnexionAPI();
        //ConnexionWebService(const char* webServiceURL=DEFAULT_API_URL, const char* authToken = DEFAULT_AUTHENTIFICATON_TOKEN);
        void connexionWiFi();
        void connexionWiFi(const char* ssid_param, const char* password_param);
        bool authenticateL(); //Authentification Lea a l'API ! Pour le final on aura une seul methode authenticate car usage d'un seul ESP !
        bool authenticateC(); //Authentification Celene a l'API
        bool authenticateA(); //Authentification An a l'API
        bool sendData(const char* jsonData);
        

};