#include "MyList.h"

int main() {
    MyList<int> list1;
    auto end1 = list1.end();
    list1.insert(end1, 1);
    list1.insert(end1, 3);
    list1.insert(end1, 5);

    MyList<int> list2;
    auto end2 = list2.end();
    list2.insert(end2, 2);
    list2.insert(end2, 4);
    list2.insert(end2, 6);

    std::cout << "List 1: " << list1 << std::endl;
    std::cout << "List 2: " << list2 << std::endl;

    list1.merge(list2);
    std::cout << "Merged List: " << list1 << std::endl;

    MyList<int> orderedList1;
    auto endo1 = orderedList1.end();
    orderedList1.insert(endo1, 1);
    orderedList1.insert(endo1, 3);
    orderedList1.insert(endo1, 5);

    MyList<int> orderedList2;
    auto endo2 = orderedList2.end();
    orderedList2.insert(endo2, 2);
    orderedList2.insert(endo2, 4);
    orderedList2.insert(endo2, 6);

    std::cout << "Ordered List 1: " << orderedList1 << std::endl;
    std::cout << "Ordered List 2: " << orderedList2 << std::endl;

    MyList<int> mergedOrderedList;
    mergedOrderedList.mergeOrdered(orderedList1, orderedList2);
    std::cout << "Merged Ordered List: " << mergedOrderedList << std::endl;

    std::cin >> mergedOrderedList;
    mergedOrderedList.erase(++mergedOrderedList.begin());

    std::cout << "New Merged List: " << mergedOrderedList;
    return 0;
}
