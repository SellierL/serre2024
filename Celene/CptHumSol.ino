//CptHumSol.ino

#include "CptHumSol.h"
#include "regulation.h"
#include "ConnexionAPI.h"

#define AOUT_PIN 35
#define THRESHOLD 1025

//déclaration des variables
CptHumSol cptHumSol(AOUT_PIN, THRESHOLD);
Robinet robinet(15);
Reservoir reservoir(21);
CptLum lumiere;
Regulation consigne;
float consignehumsol;

void setup() {
    Serial.begin(9600);

    //fermer les pompes et robinet
    reservoir.arreterPompe();
    robinet.fermerRobinet();

    //Initialisation du capteur d'humidité et d
    cptHumSol.initialisation();
    reservoir.initialisation();
}


void loop() {
  
  //attendre 5secondes
  delay(5000);

  // mesure de l'intensité lumineuse et déterminer s'il fait jour ou nuit
  lumiere.donnee();
  bool Jour = lumiere.donnee();
  // si jour on demande la consigne d'humidité du sol du jour
  if (Jour==true) {
    consignehumsol = consigne.demanderConsigneJour();
  }
    // si nuit on demande la consigne d'humidité du sol de nuit
  else
  {
    consignehumsol = consigne.demanderConsigneNuit();
  }

  // mesure de l'humidité du sol
  float donnee = cptHumSol.donnee();

 // mesure du niveau d'eau dan sle réservoir 
  float NiveauReservoirOK = reservoir.donnee();

  // régulation de l'humidité du sol
  if (donnee>consignehumsol) {
      robinet.fermerRobinet();
      reservoir.arreterPompe();
    } 
    else {
        //si il y a assez d'eau dans le réservoir
        if(NiveauReservoirOK==true) {
          robinet.fermerRobinet();
          reservoir.demarrerPompe();
        }
        //si il n'y a pas assez d'eau dans le réservoir 
        else {
           reservoir.arreterPompe();
           robinet.ouvrirRobinet();
        }
    }
}
