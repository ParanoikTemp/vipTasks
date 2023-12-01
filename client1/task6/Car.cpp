#include "Car.h"

Car::Car(string _brand, int _cylinders, float _capacity) {
    brand = new string (_brand);
    cylinders = new int (_cylinders);
    capacity = new float (_capacity);
}

Car::Car(const Car &other) {
    brand = new string (*other.brand);
    cylinders = new int (*other.cylinders);
    capacity = new float (*other.capacity);
}

Car::~Car() {
    delete brand;
    delete cylinders;
    delete capacity;
}

Car &Car::operator=(const Car &other) {
    *brand = *other.brand;
    *cylinders = *other.cylinders;
    *capacity = *other.capacity;
    return *this;
}

void Car::setCapacity(float _capacity) {
    *capacity = _capacity;
}

float Car::editCapacity(float number) {
    *capacity += number;
    return *capacity;
}

ostream &operator<<(ostream &stream, const Car &car) {
    stream << "Car: [brand: " << *car.brand << ", cylinders: " << *car.cylinders << ", capacity: " << *car.capacity << "]";
    return stream;
}

