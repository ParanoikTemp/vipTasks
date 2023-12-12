#include "Dollar.h"
#include "Euro.h"

int main() {
    // Пример использования
    Dollar dollarAmount(100.0);
    dollarAmount.display();
    std::cout << "Amount in rubles: " << dollarAmount.convertToRubles() << std::endl;

    Euro euroAmount(50.0);
    euroAmount.display();
    std::cout << "Amount in rubles: " << euroAmount.convertToRubles() << std::endl;

    return 0;
}
