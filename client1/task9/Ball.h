#pragma once
#include "Body.h"
#include <cmath>

class Ball : public Body {
private:
    double radius;

public:
    Ball(): radius(0) {}

    Ball(double r);

    Ball(const Ball& other) = default;

    ~Ball() = default;

    Ball& operator=(const Ball& other) = default;

    double getVolume() const;

    double getSurfaceArea() const;


};
