#include "CapTempHum.h"

class Regulation
{
public:
bool allumerLampe(); //Pour lampe chauffante
bool eteindreLampe(); //Pour lampe chauffante
bool allumerVent(); //Pour ventilation
bool eteindreVent(); //Pour ventilation
float demanderConsigneTemp(); //Pour demander valeurs à API Rest
float demanderConsigneHum(); //Pour demander valeurs à API Rest
};