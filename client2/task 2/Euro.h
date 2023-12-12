#pragma once
#include <iostream>
#include "Currency.h"

class Euro : public Currency {
public:
    Euro(double amount) : Currency(amount) {}

    double convertToRubles() const override;

    void display() const override;
};
