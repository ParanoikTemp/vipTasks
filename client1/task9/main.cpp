#include "Parallelepiped.h"
#include "Ball.h"
#include <iostream>

int main() {
    // Пример использования классов
    Parallelepiped parallelepiped(3.0, 4.0, 5.0);
    std::cout << "Parallelepiped:" << std::endl;
    std::cout << "Volume: " << parallelepiped.getVolume() << std::endl;
    std::cout << "Surface Area: " << parallelepiped.getSurfaceArea() << std::endl;

    std::cout << std::endl;

    Ball ball(2.5);
    std::cout << "Ball:" << std::endl;
    std::cout << "Volume: " << ball.getVolume() << std::endl;
    std::cout << "Surface Area: " << ball.getSurfaceArea() << std::endl;

    return 0;
}
