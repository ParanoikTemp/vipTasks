#include "List.h"

using namespace std;

int main() {
    List<int> list;
    auto iter = list.begin();
    list.addItem(5, iter);
    iter++;
    list.addItem(7, iter);
    iter++;
    list.addItem(13, iter);
    iter++;
    list.addItem(18, iter);
    cout << list << endl;
    iter--;
    iter--;
    list.deleteItem(iter);
    list.deleteItem(iter);
    cout << list << endl;
    cin >> list;
    cout << list;
}
