#include <iostream>
#include <windows.h>
#include <cmath>
#include <cstring>

double C2F(char* str) {
    double num = 0;
    int cnt = 0;
    bool point = false;
    while (*str != '\0' && *str != ' ') {
        if (*str == '.')
            point = true;
        else if (!point)
            num = num * 10 + (int) *str - 48;
        else
            num += ((int) *str - 48) * pow(10, -1 * ++cnt);
        ++str;
    }
    return num;
}

double extractDimension(char* furniture, const char* dimension) {
    char* pos = strstr(furniture, dimension);
    if (pos) {
        pos += strlen(dimension);
        while (*pos == ' ') ++pos;
        return C2F(pos);
    }
    return 0;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char furniture[20][200] = {
            " 01) Стул цвет - коричневый; ширина - 45.2 см; длина - 50.7 см; высота - 80.3 см",
            " 02) Шкаф цвет - серый; ширина - 90.1 см; длина - 120.5 см; высота - 180.2 см",
            " 03) Стол цвет - дубовый; ширина - 80.6 см; длина - 150.9 см; высота - 75.4 см",
            " 04) Стул цвет - черный; ширина - 40.3 см; длина - 45.8 см; высота - 85.6 см",
            " 05) Шкаф цвет - бежевый; ширина - 100.2 см; длина - 110.7 см; высота - 200.1 см",
            " 06) Стол цвет - стеклянный; ширина - 70.5 см; длина - 120.3 см; высота - 65.8 см",
            " 07) Шкаф цвет - вишневый; ширина - 80.2 см; длина - 130.6 см; высота - 190.7 см",
            " 08) Стул цвет - бежевый; ширина - 42.1 см; длина - 48.9 см; высота - 75.3 см",
            " 09) Стол цвет - черешня; ширина - 85.4 см; длина - 160.2 см; высота - 70.6 см",
            " 10) Шкаф цвет - ореховый; ширина - 95.7 см; длина - 125.8 см; высота - 185.9 см",
            " 11) Шкаф цвет - бежевый; ширина - 120.4 см; длина - 95.6 см; высота - 190.2 см",
            " 12) Шкаф цвет - черешня; ширина - 110.6 см; длина - 115.3 см; высота - 195.4 см",
            " 13) Стол цвет - белый; ширина - 75.8 см; длина - 140.6 см; высота - 73.2 см",
            " 14) Стул цвет - зеленый; ширина - 41.2 см; длина - 47.9 см; высота - 79.8 см",
            " 15) Шкаф цвет - серебристый; ширина - 105.4 см; длина - 135.7 см; высота - 205.6 см",
            " 16) Стул цвет - красный; ширина - 39.7 см; длина - 46.3 см; высота - 77.5 см",
            " 17) Стол цвет - ореховый; ширина - 90.3 см; длина - 155.8 см; высота - 68.9 см",
            " 18) Шкаф цвет - бежевый; ширина - 95.6 см; длина - 120.4 см; высота - 190.2 см",
            " 19) Стул цвет - желтый; ширина - 43.8 см; длина - 49.6 см; высота - 76.4 см",
            " 20) Стол цвет - черный; ширина - 85.2 см; длина - 150.7 см; высота - 72.1 см"
    };

    const char targetColor[] = "бежевый";
    double minVolume = -1;
    int count = 0;

    for (int i = 0; i < 20; ++i) {
        if (strstr(furniture[i], "Шкаф") && strstr(furniture[i], targetColor)) {
            double width = extractDimension(furniture[i], "ширина -");
            double length = extractDimension(furniture[i], "длина -");
            double height = extractDimension(furniture[i], "высота -");
            double volume = width * length * height;
            if (volume < minVolume || minVolume == -1) {
                minVolume = volume;
                count = 1;
            } else if (volume == minVolume) {
                ++count;
            }
        }
    }

    std::cout << "Количество бежевых шкафов минимального объема: " << count << std::endl;

    return 0;
}
