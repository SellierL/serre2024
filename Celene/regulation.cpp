//regulation.h

#include "regulation.h"


Robinet::Robinet(int PinRobinet) {
  NumRobinet = PinRobinet;
  pinMode(NumRobinet,OUTPUT);
}

bool Robinet::fermerRobinet() {

    // Fermer le robinet
    digitalWrite(NumRobinet, LOW);
}

bool Robinet::ouvrirRobinet() {

    // Ouvrir le robinet
     digitalWrite(NumRobinet, HIGH);
}

Reservoir::Reservoir(int PinPompe) {
  NumPompe = PinPompe;
  pinMode(NumPompe, OUTPUT);
}

bool Reservoir::arreterPompe() {
  // Démarer la pompe
  digitalWrite(NumPompe, LOW);  
}

bool Reservoir::demarrerPompe() {
  // Démarrer la pompe
  digitalWrite(NumPompe, HIGH);
}

void Reservoir::initialisation() {
  // Initatilasion du capteur
  Wire.begin();                
  Serial.begin(9600);       
}

float Reservoir::donnee() {
    return 0;
}

CptLum::CptLum() {}

bool CptLum::donnee() {
    return 0;
}

Regulation::Regulation() {}

float Regulation::demanderConsigneJour() {
    return 0;
}

float Regulation::demanderConsigneNuit() {
    
    return 0;
}
