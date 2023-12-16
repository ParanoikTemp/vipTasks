#include "Ball.h"

Ball::Ball(double r) : radius(r) {}

double Ball::getVolume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
}

double Ball::getSurfaceArea() const {
    return 4 * M_PI * std::pow(radius, 2);
}