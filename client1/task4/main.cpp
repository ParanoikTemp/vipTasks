#include "Goods.h"

using namespace std;

int main() {
    Goods tovar("Cat", Date{20, 11, 2023}, Money(100, 50), 20, 4120971);
    cout << tovar << endl;
    cout << "Cost: " << tovar.getCost() << endl;
    cout << "WOW! CRAZY DISCOUNT!" << endl;
    cout << "OLD PRICE: " << tovar.getPrice() << endl;
    tovar.makeDiscount(Date{28, 11, 2023});
    cout << "NEW PRICE: " << tovar.getPrice() << endl;
    tovar.reduceCount(13);
    cout << "Hurry up! Only " << tovar.getCount() << " pieces left!";
    return 0;
}
