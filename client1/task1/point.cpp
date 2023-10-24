#include "point.h"
#define EPS 1e-10

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::moveToX(double dx) {
    x += dx;
    return x;
}

double Point::moveToY(double dy) {
    y += dy;
    return y;
}

double Point::length() {
    return sqrt(x * x + y * y);
}

double Point::getDistanceToPoint(Point other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

void Point::decartToPolar(double &radius, double &angle) {
    radius = length();
    angle = atan(y / x) * 180 / M_PI;
}

bool Point::isEqual(Point other) {
    return abs(x - other.x) < EPS && abs(y - other.y) < EPS;
}

void Point::print() {
    cout << '(' << x << "; " << y << ") ";
}
