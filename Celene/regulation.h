//regulation.h

#ifndef REGULATION_H
#define REGULATION_H

#include "Arduino.h"


class Robinet {
  public:
    Robinet();
    void fermerRobinet();
    void ouvrirRobinet();

  private:
    
};

class Reservoir {
  public:
    Reservoir();
    void arreterPompe();
    void demarrerPompe();
    float donnee();

  private:
    
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
