/*
* A class for interfacing the Melexis 90620 Sensor from a Teensy 3.1
* Uses the 2c_t3 library for communication with the sensor
* 2013 by Felix Bonowski
* Based on a forum post by maxbot: http://forum.arduino.cc/index.php/topic,126244.msg949212.html#msg949212
* This code is in the public domain.
* Connection Instructions:
* Connect the Anode of a Silicon Diode to 3V Pin of Teensy. The Diode will drop ~0.7V, so the Cathode will be at ~2.7V. These 2.7V will be the supply voltage "VDD" for the sensor.
* Plug in the USB and measure the supply voltage with a multimeter! - it should be somewhere between 2.5V and 2.75V, else it will fry your precious sensor...
* ...disconnect USB again...
* Connect Teensy Pin 18 to 2.7V with a 4.7kOhm Resistor (Pullup)
* Connect Teensy Pin 19 to 2.7V with a 4.7kOhm Resistor (Pullup)
* Connect Teensy Pin 18 to I2C Data (SDA) Pin of Sensor
* Connect Teensy Pin 19 to I2C clock (SCL) Pin of Sensor
* Connect GND and 2.7V with a 100nF ceramic Capacitor.
* Connect the VSS Pin of the Sensor to GND.
* Connect the VDD Pin of the Sensor to 2.7V
* Created on: 9.7.2015   Author: Robin van Emden
*/

#include "MyApplication.h"


MyApplication cameraThermique;


void setup()
{ 
    cameraThermique.initialisation();
    //cameraThermique.alerteStressHydrique();
};

void loop()
{  
    
    float* temperatures=cameraThermique.getTemperature();
   
    uint8_t* imagePtr = cameraThermique.mapThermalDataToImage();

    //Libération de la mémoire après l'utilisation
    delete[] imagePtr;
    
    
    delay(120000);  // Attendre 2 minutes avant la prochaine lecture
};
