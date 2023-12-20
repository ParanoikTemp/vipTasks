#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree binaryTree;
    binaryTree.insert(10);
    binaryTree.insert(5);
    binaryTree.insert(15);
    binaryTree.insert(3);
    binaryTree.insert(7);
    binaryTree.insert(2);
    binaryTree.insert(6);
    binaryTree.insert(5);

    TreeNode *nodeToRemove = binaryTree.findElem(5);

    std::cout << "Before Deletion:" << std::endl;
    binaryTree.printTree();

    binaryTree.removeNode(nodeToRemove);

    std::cout << "\nAfter Deletion:" << std::endl;
    binaryTree.printTree();

    return 0;
}
