#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

class Point {
private:
    double x, y;
public:
    /// <summary> конструтор класса без значений </summary>
    Point();
    /// <summary> конструтор класса с координатами точки </summary>
    /// <param name="x"> Положение точки по оси абсцисс </param>
    /// <param name="y"> Положение точки по оси ординат </param>
    Point(double x, double y);
    /// <summary> Перемещает точку параллельно оси абсцисс </summary>
    /// <param name="dx"> Расстояние, на которое будет сдвинута точка</param>
    /// <returns> Новое положение точки по оси абсцисс </returns>
    double moveToX(double dx);
    /// <summary> Перемещает точку параллельно оси ординат </summary>
    /// <param name="dx"> Расстояние, на которое будет сдвинута точка</param>
    /// <returns> Новое положение точки по оси ординат </returns>
    double moveToY(double dy);
    /// <summary> Функция вычисления длины вектора в точке </summary>
    /// <returns> Расстояние до точки от нулевых координат </returns>
    double length();
    /// <summary> Функция вычисления расстояния от одной точки до другой </summary>
    /// <param name="other"> Вторая точка </param>
    /// <returns> Расстояние между точками </returns>
    double getDistanceToPoint(Point other);
    /// <summary> Переводит координаты точки в полярные </summary>
    /// <param name="radius"> Сюда возвращается расстояние до точки от центра координат </param>
    /// <param name="angle"> Сюда возвращается угол точки </param>
    void decartToPolar(double &radius, double &angle);
    /// <summary> Функция сравнения точек </summary>
    /// <param name="other"> Вторая точка </param>
    /// <returns> Равенство точек (правда/ложь) </returns>
    bool isEqual(Point other);
    /// <summary> Печать точки </summary>
    void print();
};
