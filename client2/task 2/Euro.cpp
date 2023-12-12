#include "Euro.h"

double Euro::convertToRubles() const {
return amount * 97.48;
}

void Euro::display() const {
std::cout << "Amount in euros: " << amount << std::endl;
}
