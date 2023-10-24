#include<iostream>
#include"point.h"
using namespace std;

int main()
{
    Point a(5, 8), b;
    a.print();
    cout << endl;
    b.print();
    b.moveToX(-4);
    b.moveToY(1);
    cout << "-> ";
    b.print();
    cout << "(length: " << b.length() << ")";
    cout << endl;
    cout << "Distance from a to b: " << a.getDistanceToPoint(b) << endl;
    double rad, fi;
    a.decartToPolar(rad, fi);
    cout << "Point a to polar cords: (" << rad << "; " << fi << ")\n";
    cout << "a " << (a.isEqual(b) ? "==" : "!=") << " b\n";
    return 0;
}
