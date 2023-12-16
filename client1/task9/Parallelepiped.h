#pragma once
#include "Body.h"

class Parallelepiped : public Body {
private:
    double length;
    double width;
    double height;

public:
    Parallelepiped(double l, double w, double h);

    double getVolume() const;

    double getSurfaceArea() const;
};