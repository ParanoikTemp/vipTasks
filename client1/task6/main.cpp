#include <iostream>
#include "Car.h"
#include "Lorry.h"

using namespace std;

int main() {
    Car mashina("Toyota", 4, 70);
    mashina.setCapacity(30);
    cout << mashina << endl;
    mashina.editCapacity(20);
    mashina.editCapacity(-10);
    cout << mashina << endl;
    Lorry lorry("Toyota", 6, 90, 1000);
    cout << lorry << endl;
    lorry.editCapacity(20);
    lorry.setBrand("BMW");
    lorry.editPayload(500);
    cout << lorry;
    return 0;
}
