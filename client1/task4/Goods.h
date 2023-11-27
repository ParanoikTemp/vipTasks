#include <string>
#include "Money.h"

using std::string;
using std::ostream;
using std::istream;

struct Date {
    int day;
    int month;
    int year;
    /// <summary> Функция для вычисления количества просроченных дней </summary>
    /// <param name="other"> дата для проверки просрочки </param>
    /// <returns> Число от 0 до 100 с количеством просроченных дней. В случае если переданная дата меньше чем срок
    /// годности товара, то вернется 0, а если просрочено более чем на 100 дней, то вернется все равно 100.</returns>
    int distanceToDays(const Date &other) const;
};

class Goods {
private:
    string name;
    Date date{};
    Money price;
    int count;
    int number;
public:
    /// <summary> Конструктор класса без параметров </summary>
    Goods();
    /// <summary> Конструктор класса без параметров </summary>
    /// <param name="_name"> Название товара </param>
    /// <param name="_date"> Срок годности товара (дата) </param>
    /// <param name="_cost"> Стоимость товара (в рублях с копейками) </param>
    /// <param name="_count"> Количество товара (шт.) </param>
    /// <param name="_number"> Номер накладной </param>
    Goods(string &_name, Date &_date, Money &_price, int _count, int _number);
    /// <summary> Конструктор копирования </summary>
    /// <param name="other"> Другой объект класса Goods </param>
    Goods(const Goods &other) = default;
    /// <summary> Деструктор класса </summary>
    ~Goods() = default;
    /// <summary> Конструктор присваивания </summary>
    /// <param name="other"> Другой объект класса Goods </param>
    /// <returns> Ссылка на данный объект </returns>
    Goods &operator=(const Goods &other) = default;
    /// <summary> Метод изменения цены товара </summary>
    /// <param="new_price"> Новая цена товара </param>
    void setPrice(const Money &new_price);
    /// <summary> Метод вычисления стоимости товара (убирает ндс и наценку) </summary>
    /// <param name="nds"> Сколько процентов добавляется к стоимости товара </param>
    /// <returns> Возвращает стоимость товара </returns>
    Money getCost(int NDS=18) const;
    /// <summary> Метод создания строки стоимости товара </summary>
    /// <returns> Возвращает строку с стоимостью товара </returns>
    string toString();
    /// <summary> Увеличивает количество товара </summary>
    /// <param name="count"> Добавляемое количество товара </param>
    void increaseCount(int count);
    /// <summary> Уменьшает количество товара </summary>
    /// <param name="count"> Убираемое количество товара </param>
    void reduceCount(int count);
    /// <summary> Уменьшает цену на 1% за каждый день просрочки </summary>
    /// <param name="today"> Сегодняшняя дата </param>
    void makeDiscount(Date &today);
};
