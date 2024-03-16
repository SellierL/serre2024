#include <ConnexionWiFi.h>

ConnexionWiFi::ConnexionWiFi(const char *ssid, const char *password)
{
    this->ssid = strdup(ssid);//alloue dynamiquement de l'espace pour les chaines de caracteres et a copier les valeurs dans l'attribut ssid
    this->password = strdup(password);//alloue dynamiquement de l'espace pour les chaines de caracteres et a copier les valeurs dans l'attribut password
}

ConnexionWiFi::ConnexionWiFi() 
{
    //Definis le ssid et le password
    this->ssid = strdup("SNIR-S10");
    this->password = strdup("gpadid@s10");
}

ConnexionWiFi::~ConnexionWiFi()
{
    free(ssid);
    free(password);
}

void ConnexionWiFi::seConnecter()
{
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

void ConnexionWiFi::seDeconnecter()
{
    WiFi.disconnect();
    Serial.println("Déconnexion WiFi");
}

bool ConnexionWiFi::estConnecte()//Est a 1 quand connecter
{
    return WiFi.status() == WL_CONNECTED;
}
