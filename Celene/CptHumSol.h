#ifndef CPTHUMSOL_H
#define CPTHUMSOL_H

#include "Arduino.h"

class CptHumSol {
public: 
  CptHumSol(int aoutPin, int threshold);
  void affiche();

private:
  int AOUT_PIN; 
  int THRESHOLD;
  int value; // Ajout de value comme membre de classe
  int moisturePercentage; // Ajout de moisturePercentage comme membre de classe
};

#endif // CPTHUMSOL_H
