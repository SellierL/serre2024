#include "CptHumSol.h"

CptHumSol::CptHumSol(int aoutPin, int threshold) {
  AOUT_PIN = aoutPin;
  THRESHOLD = threshold;
}

void CptHumSol::donnee() {
  value = analogRead(AOUT_PIN); // read the analog value from sensor
  moisturePercentage = map(value, 1675, 4095, 100, 0); // Suppose que la valeur maximale lue par le capteur est 1023
}

void CptHumSol::affiche() { //class affiche
  if (moisturePercentage>95) {
    moisturePercentage=100;
  }
  Serial.print("Le sol est humide a (");
  Serial.print(moisturePercentage);
  Serial.println("%)");
  


  delay(500);
}
