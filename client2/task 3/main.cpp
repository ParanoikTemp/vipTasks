#include "Tree.h"


int main() {
    BinaryTree binaryTree;

    // Добавляем элементы в дерево
    binaryTree.insert(50);
    binaryTree.insert(30);
    binaryTree.insert(70);
    binaryTree.insert(20);
    binaryTree.insert(40);


    // закомментируйте строку снизу, чтобы сделать последовательность монотонно возрастающей
    binaryTree.updateValue(40, 50);
    // Проверяем монотонное возрастание
    binaryTree.checkMonotonicIncreasing();

    return 0;
}
