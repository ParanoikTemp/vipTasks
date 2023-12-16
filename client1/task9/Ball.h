#pragma once
#include "Body.h"
#include <cmath>

class Ball : public Body {
private:
    double radius;

public:
    Ball(double r);

    double getVolume() const;

    double getSurfaceArea() const;
};