#include <iostream>
#include <cmath>

double integral(double x, double a, double b, int n) {
    double eax = exp(a * x);  // Экспонента в степени ax (e^ax)
    if (n == 1) {  // В случае когда степень равна 1  (Случай выхода из рекурсии)
        return eax / pow(a, 2) * (a * x - 1);
    } else {  // Предположим, что n может быть только натуральным числом
        double first_part = pow(x, n) * eax / a;  // Первая часть функции до минуса
        double recursion_part = n / a * integral(x, a, b, n - 1);  // Часть, где берется интеграл на степень ниже
        return first_part - recursion_part;
    }
}

int main() {
    std::cout << integral(2, 1, 5, 3) << std::endl;
    return 0;
}
