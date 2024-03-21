//Code créé par PHAM

#include <Arduino.h>
#include "CapTempHum.h"
#include "Regulation.h" 

// Déclaration de(s) variable(s)
CapTempHum MondhT22 (DHT22_PIN, DHT22); //Création de l'objet MondhT22 de type CapTempHum
Regulation Reguler; //Objet de Regulation


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Commence la communication en serial
  MondhT22.initCapt(); // Initialise capteur DHT22
  //Reguler.eteindreLampe() //On le laisse éteint
  //Reguler.enteindreVent() //On le laisse éteint
 
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

void loop() {
  // put your code here, to run a loop:
  test();

  /*********
  // Attendre 5s entre chaques lectures
  delay(5000); // en ms
  // Lire Température °C
  float temp = MondhT22.getTemp();
  // Lire Humidité %
  float hum  = MondhT22.getHum();
  // Demander Consigne Température;
  float consigneTemp = Reguler.demanderConsigneTemp();
  // Demander Consigne Humidité;
  float consigneHum = Reguler.demanderConsigneHum();
  if(temp > consigneTemp)
  {
    // Ne rien faire
    Reguler.eteindreLampe();
  }
  else
  {
    // Chauffer la serre
    Reguler.allumerLampe();
  }

  if(hum > consigneHum)
  {
    // Extraire air de l'humidité ambiante
    Reguler.allumerVent();
  }
  else
  {
    // Ne rien faire
    Reguler.eteindreVent();
  }
  *******/

  // Attendre 2s entre chaques lectures
  delay(2000); //en ms
}
