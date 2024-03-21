#include "CptHumSol.h"
#include "regulation.h"

#define AOUT_PIN 35
#define THRESHOLD 1025

CptHumSol cptHumSol(AOUT_PIN, THRESHOLD);
//Robinet robinet;
//Reservoir reservoir;
//Lumiere lumiere;
//Consigne consigne;

/*
void setup() {
    Serial.begin(9600);
    reservoir.arreterPompe();
    robinet.fermerRobinet();
    cptHumSol.setup();
}

void loop() {
  delay(5000);
  lumiere.donnee();
  float lum = lumiere.donnee();
  if (lum==TRUE) {
    consigne.demanderConsigneJour();
    float consignehumsol = demanderConsigneJour();
  }
   else
  {
    consigne.demanderConsigneNuit();
    float consignehumsol = demanderConsigneNuit();
  }

  float consignehumsol = demanderConsigne();
  cptHumSol.donnee();
  float donnee = cptHumSol.donnee();
  float reservoir = reservoir.donnee();

  if (donnee>consignehumsol) {
reservoir.arreter();
reservoir.arreterPompe()
    } 
    else {
        if(reservoir==TRUE) {
          reservoir.ouvrir();
        }
        else {
          robinet.ouvrir();
        }
    }
}
