//Code créé par PHAM

#include <Arduino.h>
#include "CapTempHum.h"
#include "Regulation.h"
#include "ConnexionAPI.h" 

// Déclaration de(s) variable(s)
CapTempHum MondhT22 (DHT22_PIN, DHT22); //Création objet MondhT22 de type CapTempHum
Regulation Reguler (18,19); //Objet Regulation connecté aux pins Lampe et Ventilation
ConnexionAPI MaConnexion; //Objet pour se connecter à API


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Commence la communication en serial
  MondhT22.initCapt(); // Initialise capteur DHT22
  Reguler.eteindreLampe(); //On le laisse éteint
  Reguler.eteindreVent(); //On le laisse éteint
  MaConnexion.connexionWiFi(); //Connexion salle 10
  /**MaConnexion.connexionWiFi("SSID","MDP") Connexion depuis chez soi**/

}

void test()
{
  // Lire Humidité en %
  float humi  = MondhT22.getHum();
  // Lire Température en Celsius
  float tempC = MondhT22.getTemp();
  // On vérifie si la lecture du capteur est réussie ou non
  if ( isnan(tempC) || isnan(humi) ) {
    Serial.println("Echec de la lecture du capteur DHT22!");
  } else {
  // Affiche la température en °C et l'humidité de l'air en %
  MondhT22.display();
  }
}

// Déclaration de la variable de température
float temp;

// Déclaration de la variable de l'humidité de l'air
float hum;

// Déclaration de la variable de consigne temp
float consigneTemp; //permet de voir la temp via API

// Déclaration de la variable de consigne hum
float consigneHum; //permet de voir l'hum via API

void loop() {
  // put your code here, to run a loop:
  //test();

  // Attendre 5s entre chaques lectures
  delay(5000); // en ms

  // Lire Température °C
  temp = MondhT22.getTemp();

  // Lire Humidité %
  hum  = MondhT22.getHum();

  // Demander Consigne Température;
  consigneTemp = Reguler.demanderConsigneTemp();

  // Demander Consigne Humidité;
  consigneHum = Reguler.demanderConsigneHum();

  //Affiche les consignes de temp et hum
  Reguler.afficheConsigne();

  // Régulation de la température ambiante
  if(temp > consigneTemp)
  {
    // Éteindre la lampe
    Reguler.eteindreLampe();
  }
  else
  {
    // Chauffer la serre
    Reguler.allumerLampe();
  }

  // Régulation de l'humidité de l'air ambiant
  if(hum > consigneHum)
  {
    // Extraire air de l'humidité ambiante
    Reguler.mettreEnRouteVent();
  }
  else
  {
    // Éteindre la ventilation
    Reguler.eteindreVent();
  }
}
