#include "BinaryTree.h"

int main() {
    BinaryTree tree;

    // Добавление элементов в дерево
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Установка значения parent
    tree.setParent();

    // Вывод дерева в прямом порядке
    std::cout << "In-order traversal: ";
    tree.printInOrder();

    return 0;
}
