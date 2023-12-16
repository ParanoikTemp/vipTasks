#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(double l, double w, double h) : length(l), width(w), height(h) {}

// Реализация функций вычисления объема и площади поверхности для параллелепипеда
double Parallelepiped::getVolume() const {
    return length * width * height;
}

double Parallelepiped::getSurfaceArea() const {
    return 2 * (length * width + length * height + width * height);
}