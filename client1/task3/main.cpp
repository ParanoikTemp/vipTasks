#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List arr;
    bool run = true;
    int doing;
    int index, value;
    while (run) {
        arr.print(); cout << " length: " << arr.length() << endl;
        cout << "Select an operation: \n";
        cout << "0) random nums\n";
        cout << "1) Insert item to index\t2) Insert item to head\n";
        cout << "3) Insert item to tail\t4) Insert item after other item\n";
        cout << "5) Delete item to index\t6) Delete item to head\n";
        cout << "7) Delete item to end\t8) Delete item after other item\n";
        cout << "9) Delete item\t10) Clear list\n";
        cout << "11) Replace item to index\t12) Is item in list?\n";
        cout << "13) Count item in list\t14) Get item to index\n";
        cin >> doing;
        switch (doing) {
            case 0:
                cout << endl << "Enter array length: "; cin >> value; cout << endl;
                for (int i = 0; i < value; ++i)
                    arr.pushToEnd(rand() % 100);
                cout << endl;
                break;
            case 1:
                cout << endl << "Enter the item: "; cin >> value; cout << endl;
                cout << endl << "Enter the index: "; cin >> index; cout << endl;
                arr.pushToIndex(value, index);
                cout << endl;
                break;
            case 2:
                cout << endl << "Enter the item: "; cin >> value; cout << endl;
                arr.pushToHead(value);
                cout << endl;
                break;
            case 3:
                cout << endl << "Enter the item: "; cin >> value; cout << endl;
                arr.pushToEnd(value);
                cout << endl;
                break;
            case 4:
                cout << endl << "Enter the item: "; cin >> value; cout << endl;
                cout << endl << "Enter the other item: "; cin >> index; cout << endl;
                arr.pushAfterNum(value, index);
                cout << endl;
                break;
            case 5:
                cout << endl << "Enter the index: "; cin >> index; cout << endl;
                arr.removeToIndex(index);
                cout << endl;
                break;
            case 6:
                arr.removeToHead();
                cout << endl;
                break;
            case 7:
                arr.removeToEnd();
                cout << endl;
                break;
            case 8:
                cout << endl << "Enter the item: "; cin >> value; cout << endl;
                arr.removeAfterNum(value);
                cout << endl;
                break;
            case 9:
                cout << endl << "Enter the item: "; cin >> value; cout << endl;
                arr.removeItem(value);
                cout << endl;
                break;
            case 10:
                arr.clear();
                cout << endl;
                break;
            case 11:
                cout << endl << "Enter the item: "; cin >> value; cout << endl;
                cout << endl << "Enter the index: "; cin >> index; cout << endl;
                arr.replaceToIndex(value, index);
                cout << endl;
                break;
            case 12:
                cout << endl << "Enter the item: "; cin >> value; cout << endl;
                cout << "Number " << value << (arr.isInclude(value) ? " " : " not ") << "include in list!";
                cout << endl;
                break;
            case 13:
                cout << endl << "Enter the item: "; cin >> value; cout << endl;
                cout << "Count number " << value << " in list: " << arr.count(value) << " items.";
                cout << endl;
                break;
            case 14:
                cout << endl << "Enter the index: "; cin >> index; cout << endl;
                cout << "Number to index " << index << " is " << arr.getToIndex(index);
                cout << endl;
                break;
            default:
                run = false;
                cout << "\n\nGoodbye!";
                break;
        }
    }
    return 0;
}
