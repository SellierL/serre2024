#include "MyApplication.h"


MyApplication::MyApplication()
{
    tabTemp[64];
}

void MyApplication::initialisation()
{    
    Serial.begin(115200); //vitesse de transmission serial
    while (!Serial);

    Serial.println(F("trying to initialize sensor..."));
    sensorMLX.setRefreshRate(RATE_8HZ);
    sensorMLX.setResolution(RES_17bit);
    sensorMLX.setEmissivity(1.0);
    sensorMLX.initialize (); // start the thermo cam
    Serial.println(F("sensor initialized!"));

    connexion.connexionWiFi();
}

void MyApplication::setSeuil()
{

}

float MyApplication::getTemperature()
{
    sensorMLX.measure(true); //Important ! Get NEW readings from the sensor
    //Récupére une valeur de température pour chaque pixel
    for (int i=0; i<64; i++)
    {
        tabTemp[i]=sensorMLX.getTemperature(i);

        //Affichage pour vérifier les valeurs
        Serial.print("Pixel: ");
        Serial.print(i);
        Serial.print(" / Temperature: ");
        Serial.println(tabTemp[i]);
    }

    //Vérification du stress hydrique
    if(tabTemp[32]<= seuil)
    {
        alerteStressHydrique();
    }
    return (tabTemp[64]);

    delay(10000);  // Attendre 10 secondes avant la prochaine lecture
}

void MyApplication::mapThermalDataToImage(const float *tableTemp, uint8_t *image)
{
    
}

//Régulation pour l'envoie d'un mail au laboratoire quand le seuil de température est dépassé pour le pixel au centre de l'image
void MyApplication::alerteStressHydrique()
{
    //Test de la connexion WiFi avant l'envoie de la donnee
    if (!WiFi.isConnected()) 
    {
        Serial.println("Erreur : Pas de connexion Wi-Fi.");
        Serial.println("Tentative de reconnexion... ");
        connexion.connexionWiFi();
    }
    
     
    // Déclarer l’objet SMTPSession global utilisé pour le transport SMTP
    SMTPSession smtp;

    Serial.println("Waiting for NTP server time reading");
        
    // Configuration de l'horloge en utilisant un serveur NTP pour synchroniser le temps
    configTime(3600, 0, "pool.ntp.org", "time.nist.gov");
    while (time(nullptr) < ESP_MAIL_CLIENT_VALID_TS)
    {
        delay(100);
    }
        
    // Set the network reconnection option
    MailClient.networkReconnect(true);   
         
    smtp.debug(1);
    smtp.setTCPTimeout(10);


    // Déclarer Session_Config pour les informations d’identification de session définies par l’utilisateur 
    Session_Config config;

    // Définition de la configuration de la session 
    config.server.host_name = "smtp.gmail.com";
    config.server.port = 587;
    config.login.email = "sellier.lea@gmail.com";
    config.login.password = "pehj biyy lmuc bhbp";
    config.login.user_domain = F("172.18.10.19");

    // Déclarer SMTP_Message pour les informations du message à envoyer définies par l’utilisateur 
    SMTP_Message message;

    // Définition de l'en-tête du message 
    message.sender.name = F("Green Tech Connect");
    message.sender.email = "sellier.lea@gmail.com";
    message.addRecipient(F("Green Tech Connect"), "lea.sellier@lyceeppr.fr");

    // Le format temporel de l’horodatage à injecter dans le sujet ou le contenu en utilisant la fonction strftime C++ 
    message.timestamp.tag = "#esp_mail_current_time";

    // L’étiquette qui sera remplacée par l’horodatage actuel 
    message.timestamp.format = "%B %d, %Y %H:%M:%S";

    //Définition de l'objet du mail
    message.subject = F("ALERTE: Stress Hydrique !");

    //Contenue du mail
    char content[300];
    sprintf(content, "Votre plante montre des signes de stress hydrique. D'après l'expérience définie pour cette serre, le seuil est à %.2f °C.\n\nCe message est automatique, merci de ne pas y répondre.\n\nSent #esp_mail_current_time", seuil);
    message.text.content = content;

    //Affiche les différentes erreurs rencontrés
    if (!smtp.connect(&config))
    {
        MailClient.printf("Connection error, Status Code: %d, Error Code: %d, Reason: %s\n", smtp.statusCode(), smtp.errorCode(), smtp.errorReason().c_str());
        return;
    }

    if (!smtp.isLoggedIn())
    {
        Serial.println("Not yet logged in.");
    }
    else
    {
        if (smtp.isAuthenticated())
            Serial.println("Successfully logged in.");
        else
            Serial.println("Connected with no Auth.");
    }

    if (!MailClient.sendMail(&smtp, &message))
        MailClient.printf("Error, Status Code: %d, Error Code: %d, Reason: %s\n", smtp.statusCode(), smtp.errorCode(), smtp.errorReason().c_str());
    
}


void MyApplication::envoieImageAPI()
{

}




