#include <iostream>
#include <string>

int main() {
    // Создаем переменную для хранения имени
    std::string name;
    // Создаем переменную для хранению возраста. Это целое положительное число
    unsigned int age;
    // Это переменная года, который сейчас
    const int year = 2024;
    // Просим пользователя ввести имя
    std::cout << "Enter name: ";
    // Получаем строку с именем человека. Берем ее через getline, на случай если имя "Санта Мария"
    std::getline(std::cin, name);
    // Просим пользователя ввести возраст
    std::cout << "Enter age: ";
    // Через поток ввода получаем значение возраста
    std::cin >> age;
    // Обращаемся к пользователю и говорим ему два вероятных года рождения.
    std::cout << name << ", your year of birth: " << year - age << " or " << year - age - 1 << std::endl;
    return 0;
}
