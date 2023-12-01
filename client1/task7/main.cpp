#include <iostream>
#include "queue.h"

using namespace std;
int main()
{
    Car car1("Toyota", 4, 60), car2("BMW", 6, 100);
    Queue<Car> cars;
    cars.enqueue(car1);
    cars.enqueue(car2);
    cout << cars.dequeue() << endl;
    cout << cars.dequeue();
}
