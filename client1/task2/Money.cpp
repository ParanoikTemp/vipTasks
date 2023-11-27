#include "Money.h"

Money::Money() {
    ruble = new long (0);
    kopeck = new unsigned char (0);
}

Money::Money(long ruble) {
    this->ruble = new long (ruble);
    kopeck = new unsigned char (0);
}

Money::Money(long ruble, unsigned char kopeck) {
    this->ruble = new long (ruble);
    this->kopeck = new unsigned char (kopeck);
    if (kopeck >= 100) {
        *(this->ruble) += kopeck / 100;
        *(this->kopeck) = kopeck % 100;
    }
}

Money::Money(const Money &other) {
    this->ruble = new long (*(other.ruble));
    this->kopeck = new unsigned char (*(other.kopeck));
}

Money::~Money() {
    delete ruble;
    delete kopeck;
}

Money Money::operator+(const Money &other) const {
    return Money(*ruble + *(other.ruble), *kopeck + *(other.kopeck));
}

Money Money::operator-(const Money &other) const {
    return Money(*ruble - *(other.ruble) - (*kopeck >= *(other.kopeck) ? 0 : 1), *kopeck + (*kopeck >= *(other.kopeck) ? 0 : 100) - *(other.kopeck));
}

Money Money::operator*(int count) const {
    return Money(*ruble * count, *kopeck * count);
}

Money Money::operator/(int count) const {
    double num = (double) *ruble / count;
    return Money(*ruble / count, *kopeck / count + round((num - floor(num)) * 100));
}

Money& Money::operator=(const Money &other) {
    *ruble = *(other.ruble);
    *kopeck = *(other.kopeck);
    return *this;
}

bool Money::operator==(const Money &other) const {
    return *ruble == *(other.ruble) && *kopeck == *(other.kopeck);
}

bool Money::operator!=(const Money &other) const {
    return !(*this == other);
}

bool Money::operator>(const Money &other) const {
    return *ruble > *(other.ruble) || *ruble == *(other.ruble) && *kopeck > *(other.kopeck);
}

bool Money::operator>=(const Money &other) const {
    return *this > other || *this == other;
}

bool Money::operator<(const Money &other) const {
    return !(*this >= other);
}

bool Money::operator<=(const Money &other) const {
    return !(*this > other);
}

ostream &operator<<(ostream &stream, const Money &money) {
    stream << *(money.ruble) << " rub. " << *(money.kopeck) << " cop. ";
    return stream;
}

std::istream& operator>>(std::istream& input, Money& money) {
    input >> *money.ruble;
    int num;
    input >> num;
    *money.ruble += num / 100;
    *money.kopeck = num % 100;
    return input;
}
