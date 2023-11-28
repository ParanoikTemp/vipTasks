#include "Goods.h"
#define MAX_COUNT 999999

int Date::distanceToDays(const Date &other) const {
    int month_days[12] = {31, 28, 31,30,31,30,31,31,30,31,30,31};
    int days = 0;
    if (other.year > year) {
        for (int i = 11; i > month - 1; --i) {
            days += month_days[i];
            if (i == 1 && year % 4 == 0)
                days += 1;
        }
        days += month_days[month - 1] - day;
        for (int i = 0; i < other.month - 1; ++i) {
            days += month_days[i];
            if (i == 1 && other.year % 4 == 0)
                days += 1;
        }
        days += other.day;
    } else if (other.year == year) {
        if (other.month > month) {
            days += month_days[month - 1] - day;
            for (int i = month + 1; i < other.month; ++i) {
                days += month_days[i - 1];
                if (i == 2 && year % 4 == 0)
                    days += 1;
            }
            days += other.day;
        } else if (other.month == month && other.day > day) {
            days += other.day - day;
        }
    }
    if (days > 100)
        days = 100;
    return days;
}

ostream &operator<<(ostream &stream, const Date &other) {
    stream << '[' << other.day << '/' << other.month << '/' << other.year << ']';
    return stream;
}

Goods::Goods() {
    name = "Без названия";
    date = Date{1, 1, 2024};
    price = Money(0);
    count = 0;
    number = 0;
}

Goods::Goods(string _name, Date _date, Money _price, int _count, int _number) {
    name = _name;
    date = _date;
    price = _price;
    count = _count;
    if (count < 0)
        count = 0;
    number = _number;
}

void Goods::setPrice(const Money &new_price) {
    price = new_price;
}

Money Goods::getCost(int NDS) const {
    return (price * 100) / (100 + NDS);
}

string Goods::toString() {
    return getCost().toString();
}

void Goods::increaseCount(int count) {
    if (count <= 0)
        return;
    this->count += count;
    if (this->count > MAX_COUNT)  // Чтобы в какой-то момент не переполнить переменную
        this->count = MAX_COUNT;
}

void Goods::reduceCount(int count) {
    if (count <= 0)
        return;
    this->count -= count;
    if (this->count < 0)  // Товара не может быть меньше нуля
        this->count = 0;
}

void Goods::makeDiscount(Date today) {
    int days = date.distanceToDays(today);
    price = price * 100;
    price = price * (100 - days) / 100;
    price = price / 100;
}

string Goods::getName() {
    return name;
}

int Goods::getCount() {
    return count;
}

int Goods::getNumber() {
    return number;
}

ostream &operator<<(ostream &stream, const Goods &other) {
    stream << "Goods(Name: " << other.name << ", Date: " << other.date << ", Price: " << other.price << ", Count: " << other.count << ", Number: " << other.number << ")";
    return stream;
}

Money Goods::getPrice() {
    return price;
}
