//#ifndef CPTHUMSOL_H
#define CPTHUMSOL_H

#include "Arduino.h"

class CptHumSol {
public: 
  CptHumSol(int aoutPin, int threshold);
  void affiche();
  float donnee();
  void initialisation();

private:
  int AOUT_PIN; 
  int THRESHOLD;
  int value; 
  int moisturePercentage; 
};