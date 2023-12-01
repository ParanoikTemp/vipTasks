#include "Lorry.h"

Lorry::Lorry(string _brand, int _cylinders, float _capacity, int _payload) : Car(_brand, _cylinders, _capacity) {
    payload = new int (_payload);
}

Lorry::Lorry(const Lorry &other) : Car(other) {
    payload = new int (*other.payload);
}

Lorry::~Lorry() {
    delete payload;
}

Lorry &Lorry::operator=(const Lorry &other) {
    Car::operator=(other);
    *payload = *other.payload;
    return *this;
}

ostream &operator<<(ostream &stream, const Lorry &lorry) {
    stream << "Lorry: [brand: " << *lorry.brand << ", cylinders: " << *lorry.cylinders << ", capacity: " << *lorry.capacity << ", payload: " << *lorry.payload << "]";
    return stream;
}

void Lorry::setBrand(string _brand) {
    *brand = _brand;
}

int Lorry::editPayload(int number) {
    *payload += number;
    return *payload;
}
