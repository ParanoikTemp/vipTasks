#include <iostream>
#include <string>
#include <windows.h>

std::string fixText(const std::string& text) {
    std::string result;
    const std::string liters[] = {"а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р",
                                "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я"};
    for (char i : text) {
        if (i >= -32 && i <= -1)
            result += liters[abs(-32 - i)];
        else
            result += i;
    }
    return result;
}

unsigned int convertToNumber(std::string input) {

    unsigned int result = 0;  // Тут будем собирать результат
    int pos = 0;  // Тут у нас хранится позиция для скачков между словами
    int len = input.length();  // Тут храним длину полученного текста

    while (pos < len) {  // Работаем пока мы не дойдем переменной pos в конце текста
        int spacePos = input.find(' ', pos);  // Получаем индекс ближайшего пробела
        if (spacePos == std::string::npos) {  // Если пробелов нет, значит либо мы работаем с последним словом, либо это цельное число
            spacePos = len;  // детектим сюда финальный индекс
        }

        std::string word = input.substr(pos, spacePos - pos);  // Вырезаем слово

        if (isdigit(word[0])) {  // если слово состоит чисто из цифр, то есть встроенный метод для перевода строки в число
            result += stoi(word);
        } else {  // если состоит из слов, то по тому, какое тут слово, добавляем число к сумме возраста
            if (word == "ноль") result += 0;
            else if (word == "один") result += 1;
            else if (word == "два") result += 2;
            else if (word == "три") result += 3;
            else if (word == "четыре") result += 4;
            else if (word == "пять") result += 5;
            else if (word == "шесть") result += 6;
            else if (word == "семь") result += 7;
            else if (word == "восемь") result += 8;
            else if (word == "девять") result += 9;
            else if (word == "десять") result += 10;
            else if (word == "одиннадцать") result += 11;
            else if (word == "двенадцать") result += 12;
            else if (word == "тринадцать") result += 13;
            else if (word == "четырнадцать") result += 14;
            else if (word == "пятнадцать") result += 15;
            else if (word == "шестнадцать") result += 16;
            else if (word == "семнадцать") result += 17;
            else if (word == "восемнадцать") result += 18;
            else if (word == "девятнадцать") result += 19;
            else if (word == "двадцать") result += 20;
            else if (word == "тридцать") result += 30;
            else if (word == "сорок") result += 40;
            else if (word == "пятьдесят") result += 50;
            else if (word == "шестьдесят") result += 60;
            else if (word == "семьдесят") result += 70;
            else if (word == "восемьдесят") result += 80;
            else if (word == "девяносто") result += 90;
            else if (word == "сто") result += 100;
        }

        pos = spacePos + 1;  // Сдвигаем нашу текущую позицию. А дальше фикл повторяется. Или кончается
    }

    return result;  // Возвращаем результат
}

int main() {
    SetConsoleCP ( 1251 );
    SetConsoleOutputCP ( 1251 );

    // Создаем переменную для хранения имени
    std::string name;
    // Создаем переменную для хранения текстового возраста
    std::string age_text;
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
    // Получаем строку с возрастом человека.
    std::getline(std::cin, age_text);
    age_text = fixText(age_text);
    // Перерабатываем текст в число
    age = convertToNumber(age_text);
    // Обращаемся к пользователю и говорим ему два вероятных года рождения.
    std::cout << name << ", your year of birth: " << year - age << " or " << year - age - 1 << std::endl;
    return 0;
}
