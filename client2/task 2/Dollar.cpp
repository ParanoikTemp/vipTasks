#include "Dollar.h"

double Dollar::convertToRubles() const {
    return amount * 90.0;
}

void Dollar::display() const {
std::cout << "Amount in dollars: " << amount << std::endl;
}
