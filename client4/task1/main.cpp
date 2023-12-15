#include <iostream>
#include "Tree.h"

int main() {
    BinaryTree tree;

    // Добавление элементов в дерево
    for (int i = 0; i < 20; ++i) {
        tree.addNode(rand() % 30);
    }

    // Пример использования новых методов
    tree.printTree();

    tree.moveToRight();
    tree.moveToLeft();
    auto p1 = tree.getCursorNode();
    // Ваш код дополнительных операций с деревом

    tree.moveToRoot();
    tree.moveToRight();
    tree.moveToRight();
    tree.moveToLeft();
    tree.moveToRight();
    auto p2 = tree.getCursorNode();

    tree.moveToRoot();
    tree.moveToLeft();
    tree.moveToRight();
    tree.moveToLeft();
    auto p3 = tree.getCursorNode();

    std::cout << p1->value << " " << "Level: " << p1->getLevel() << std::endl;
    std::cout << p2->value << " " << "Level: " << p2->getLevel() << std::endl;
    std::cout << p3->value << " " << "Level: " << p3->getLevel() << std::endl;

    return 0;
}

