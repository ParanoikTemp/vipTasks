#pragma once

class Currency {
protected:
    double amount; // Сумма в валюте

public:
    Currency(double amount) : amount(amount) {}

    virtual double convertToRubles() const = 0;

    virtual void display() const = 0;

    virtual ~Currency() = default;
};
