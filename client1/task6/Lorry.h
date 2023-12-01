#pragma once
#include "Car.h"

class Lorry: public Car{
protected:
    int *payload;
public:
    /// <summary> Конструктор класса </summary>
    /// <param name="_brand"> Марка автомобиля </param>
    /// <param name="_cylinders"> Количество цилиндров в двигателе </param>
    /// <param name="_capacity"> Мощность </param>
    /// <param name="_payload"> Грузоподъемность грузовика </param>
    Lorry(string _brand, int _cylinders, float _capacity, int _payload);
    /// <summary> Конструктор копирования </summary>
    /// <param name="other"> Другой объект класса Lorry </param>
    Lorry(const Lorry &other);
    /// <summary> Деструктор </summary>
    virtual ~Lorry();
    /// <summary> Конструктор присваивания </summary>
    /// <param name="other"> Другой объект класса Lorry </param>
    Lorry &operator=(const Lorry &other);

    /// <summary> Изменяет марку грузовика </summary>
    /// <param name="_brand"> Марка грузовика </param>
    void setBrand(string _brand);
    /// <summary> Изменяет грузоподъемности </summary>
    /// <param name="number"> Изменение грузоподъемности (как положительное, так и отрицательное) </param>
    /// <returns> Новое значение грузоподъемности </returns>
    int editPayload(int number);

    /// <summary> Конструктор оператора вывода </summary>
    friend ostream &operator<<(ostream &stream, const Lorry &lorry);
};
