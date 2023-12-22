#include "BinaryTree.h"

void BinaryTree::insertRecursive(TreeNode *current, int value, TreeNode *parent, int num) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }
    if (current == nullptr) {
        current = new TreeNode(value);
        if (num < 0)
            parent->left = current;
        else if (num > 0)
            parent->right = current;
    } else if (value < current->data) {
        insertRecursive(current->left, value, current, -1);
    } else {
        insertRecursive(current->right, value, current, 1);
    }
}

void BinaryTree::setParentRecursively(TreeNode *current) {
    if (current != nullptr) {
        if (current->left != nullptr) {
            current->left->parent = current;
            setParentRecursively(current->left);
        }
        if (current->right != nullptr) {
            current->right->parent = current;
            setParentRecursively(current->right);
        }
    }
}

void BinaryTree::insert(int value) {
    insertRecursive(root, value, nullptr, 0);
}

void BinaryTree::setParent() {
    setParentRecursively(root);
}

void BinaryTree::printInOrder(TreeNode *current) const {
    if (current != nullptr) {
        printInOrder(current->left);
        std::cout << current->data << " ";
        printInOrder(current->right);
    }
}

void BinaryTree::printInOrder() const {
    printInOrder(root);
    std::cout << std::endl;
}
