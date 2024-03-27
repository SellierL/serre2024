//regulation.h

#ifndef REGULATION_H
#define REGULATION_H

#include "Arduino.h"
#include <Wire.h>




class Robinet {
  public:
    Robinet(int PinRobinet);
    bool fermerRobinet();
    bool ouvrirRobinet();

  private:
  int NumRobinet;

    
};

class Reservoir {
  public:
    Reservoir(int PinPompe1);
    bool arreterPompe();
    bool demarrerPompe();
    void initialisation();
    float donnee();

  private:
  int NumPompe;
    
};

class CptLum {
  public:
    CptLum();
    bool donnee();

    private:
};

class Regulation {
  public:
    Regulation();
    float demanderConsigneJour();
    float demanderConsigneNuit();

  private:
};

#endif
