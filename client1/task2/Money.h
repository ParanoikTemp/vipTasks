#include <ostream>
#include <cmath>

using namespace std;

class Money {
private:
    long *ruble;
    unsigned char *kopeck;  // аналогичен byte из std, но поддерживает арифметические операции
public:
    /// <summary> конструтор класса без значений </summary>
    Money();
    /// <summary> конструтор класса только с значением рублей </summary>
    Money(long ruble);
    /// <summary> конструтор класса с значением рублей и копеек </summary>
    Money(long ruble, unsigned char kopeck);
    /// <summary> конструтор копирования </summary>
    Money(const Money &other);
    /// <summary> Деструктор класса </summary>
    ~Money();

    /// <summary> Оператор сложения </summary>
    /// <param name="other"> Другой объект класса Money </param>
    /// <returns> Новый объект класса Money </returns>
    Money operator+(const Money &other) const;
    /// <summary> Оператор вычитания </summary>
    /// <param name="other"> Другой объект класса Money </param>
    /// <returns> Новый объект класса Money </returns>
    Money operator-(const Money &other) const;
    /// <summary> Оператор умножения </summary>
    /// <param name="other"> Число </param>
    /// <returns> Новый объект класса Money </returns>
    Money operator*(int count) const;
    /// <summary> Оператор деления </summary>
    /// <param name="other"> Число </param>
    /// <returns> Новый объект класса Money </returns>
    Money operator/(int count) const;

    /// <summary> Оператор равенства </summary>
    /// <param name="other"> Другой объект класса Money </param>
    /// <returns> Возвращает True, если объекты равны. В противном случае false </returns>
    bool operator==(const Money &other) const;
    /// <summary> Оператор неравенства </summary>
    /// <param name="other"> Другой объект класса Money </param>
    /// <returns> Возвращает True, если объекты не равны. В противном случае false </returns>
    bool operator!=(const Money &other) const;
    /// <summary> Оператор больше </summary>
    /// <param name="other"> Другой объект класса Money </param>
    /// <returns> Возвращает True, если этот объект больше передаваемого. В противном случае false </returns>
    bool operator>(const Money &other) const;
    /// <summary> Оператор больше или равно </summary>
    /// <param name="other"> Другой объект класса Money </param>
    /// <returns> Возвращает True, если этот объект больше или равен передаваемогу. В противном случае false </returns>
    bool operator>=(const Money &other) const;
    /// <summary> Оператор меньше </summary>
    /// <param name="other"> Другой объект класса Money </param>
    /// <returns> Возвращает True, если этот объект меньше передаваемого. В противном случае false </returns>
    bool operator<(const Money &other) const;
    /// <summary> Оператор меньше или равно </summary>
    /// <param name="other"> Другой объект класса Money </param>
    /// <returns> Возвращает True, если этот объект меньше или равен передаваемогу. В противном случае false </returns>
    bool operator<=(const Money &other) const;

    /// <summary> Оператор присваивания </summary>
    /// <param name="other"> Другой объект класса Money </param>
    /// <returns> Возвращает ссылку на текущий объект </returns>
    Money& operator=(const Money &other);

    /// <summary> Оператор вывода в поток </summary>
    /// <param name="stream"> Ссылка на поток </param>
    /// <param name="money"> Текущий объект класса Money </param>
    /// <returns> Возврщает ссылку на измененный поток </returns>
    friend ostream& operator<<(ostream &stream, const Money &money);
    /// <summary> Оператор получения данных из потока </summary>
    /// <param name="money"> Ссылка на поток </param>
    /// <param name="stream"> Текущий объект класса Money </param>
    /// <returns> Возврщает ссылку на измененный поток </returns>
    friend istream& operator>>(istream &stream, Money &money);
};
