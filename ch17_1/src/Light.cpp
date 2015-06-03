#include "Light.h"

Light::Light(float x, float y, float z, float brightness){
    this->x = x;
    this->y = y;
    this->z = z;
    this->brightness = brightness;
}

void Light::setBrightness(float b) {
    brightness = MAX(b, 0);
    brightness = MIN(brightness, 1);
}