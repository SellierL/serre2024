#include "MLX90621.h"
#include <Wire.h>
#include <Arduino.h>
#include <opencv2/opencv.hpp> // Pour la creation d'image avec les bonnes dimensions

#define NUM_COLUMN 16
#define NUM_ROW 4

using namespace cv;

class CameraThermique : public MLX90621
{

    private:
    
        MLX90621 sensor;
        const int DEFAULT_ADDRESS = 0x33; // Valeur par défaut de l'adresse
        const int DEFAULT_RESOLUTION = 640; // Valeur par défaut de la résolution
        int address;
        int resolution_;


    public:
        CameraThermique();
        CameraThermique(int addressAdd);
        CameraThermique(int addressAdd, int resolutionAdd);
        void init();
        void getTemperature();
        void averageTemperature();
        Vec3b mapTemperatureToColor(float temperature);
        void saveImage();
        



};