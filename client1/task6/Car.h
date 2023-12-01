#pragma once
#include <ostream>
#include <string>

using std::string;
using std::ostream;

class Car {
protected:
    string *brand;
    int *cylinders;
    float *capacity;
public:
    /// <summary> Конструктор класса </summary>
    /// <param name="_brand"> Марка автомобиля </param>
    /// <param name="_cylinders"> Количество цилиндров в двигателе </param>
    /// <param name="_capacity"> Мощность </param>
    Car(string _brand, int _cylinders, float _capacity);
    /// <summary> Конструктор копирования </summary>
    /// <param name="other"> Другой объект класса Car </param>
    Car(const Car &other);
    /// <summary> Деструктор </summary>
    virtual ~Car();
    /// <summary> Конструктор присваивания </summary>
    /// <param name="other"> Другой объект класса Car </param>
    Car &operator=(const Car &other);

    /// <summary> Устанавливает новое значение мощности </summary>
    /// <param name ="_capacity"> Мощность </param>
    void setCapacity(float _capacity);
    /// <summary> Изменяет текущее значение мощности </summary>
    /// <param name="number"> Изменение мощности (как положительное, так и отрицательное) </param>
    /// <returns> Новое значение мощности </returns>
    float editCapacity(float number);

    /// <summary> Конструктор оператора вывода </summary>
    friend ostream &operator<<(ostream &stream, const Car &car);
};
