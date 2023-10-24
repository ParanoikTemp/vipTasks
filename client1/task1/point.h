#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

class Point {
private:
    double x, y;
public:
    Point();
    Point(double x, double y);
    double moveToX(double dx);
    double moveToY(double dy);
    double length();
    double getDistanceToPoint(Point other);
    void decartToPolar(double &radius, double &angle);
    bool isEqual(Point other);
    void print();
};
