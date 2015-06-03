#include "Point3D.h"

Point3D::Point3D(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point3D::setVanishingPoint(float vpX, float vpY) {
    this->vpX = vpX;
    this->vpY = vpY;
}

void Point3D::setCenter(float cX, float cY, float cZ) {
    this->cX = cX;
    this->cY = cY;
    this->cZ = cZ;
}

float Point3D::screenX() {
    float scale = fl / (fl + z + cZ);
    return vpX + (cX + x) * scale;
}

float Point3D::screenY() {
    float scale = fl / (fl + z + cZ);
    return vpY + (cY + y) * scale;
}

void Point3D::rotateX(float angleX) {
    float cosX = cos(angleX);
    float sinX = sin(angleX);
    float y1 = y * cosX - z * sinX;
    float z1 = z * cosX + y * sinX;
    y = y1;
    z = z1;
}

void Point3D::rotateY(float angleY) {
    float cosY = cos(angleY);
    float sinY = sin(angleY);
    float x1 = x * cosY - z * sinY;
    float z1 = z * cosY + x * sinY;
    x = x1;
    z = z1;
}

void Point3D::rotateZ(float angleZ) {
    float cosZ = cos(angleZ);
    float sinZ = sin(angleZ);
    float x1 = x * cosZ - y * sinZ;
    float y1 = y * cosZ + x * sinZ;
    x = x1;
    y = y1;
}
