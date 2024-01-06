#pragma once
#include "Body.h"

class Parallelepiped : public Body {
private:
    double length;
    double width;
    double height;

public:
    Parallelepiped(): length(0), width(0), height(0) {}

    Parallelepiped(double l, double w, double h);

    Parallelepiped(const Parallelepiped& other) = default;

    ~Parallelepiped() = default;

    Parallelepiped& operator=(const Parallelepiped& other) = default;

    double getVolume() const;

    double getSurfaceArea() const;
};
