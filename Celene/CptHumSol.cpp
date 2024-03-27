// CptHumSol.cpp
#include "CptHumSol.h"

CptHumSol::CptHumSol(int aoutPin, int threshold) {
  AOUT_PIN = aoutPin;
  THRESHOLD = threshold;
}

float CptHumSol::donnee() {
  value = analogRead(AOUT_PIN); 
  moisturePercentage = map(value, 1675, 4095, 0, 100); 
}

void CptHumSol::affiche() {
  if (moisturePercentage > 95) {
    moisturePercentage = 100;
  }
  Serial.print("Le sol est humide à (");
  Serial.print(moisturePercentage);
  Serial.println("%)");
  delay(500);
}

void CptHumSol::initialisation(){
  Serial.begin(9600);
}