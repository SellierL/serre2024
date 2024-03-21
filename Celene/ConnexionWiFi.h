#include <WiFi.h>
#include <HTTPClient.h>

#define DEFAULT_SSID "SNIR-S10"
#define DEFAULT_PASSWORD "gpadid@s10"

class ConnexionWiFi{

    private:
        char* ssid;
        char* password;

    public:
        ConnexionWiFi(const char* ssid, const char* password);
        ConnexionWiFi();
        ~ConnexionWiFi();
        void seConnecter();
        void seDeconnecter();
        bool estConnecte();
};S