#pragma once
#include <iostream>
#include "Currency.h"

class Dollar : public Currency {
public:
    Dollar(double amount) : Currency(amount) {};

    double convertToRubles() const override;

    void display() const override;
};
