#include "Tree.h"

bool BinaryTree::isMonotonicIncreasing(TreeNode *node, int &prevValue) {
    if (node == nullptr) {
        return true;
    }

    // Проверяем левое поддерево
    if (!isMonotonicIncreasing(node->left, prevValue)) {
        return false;
    }

    // Проверяем текущий узел
    if (node->data <= prevValue) {
        std::cout << "Node address: " << node << std::endl;
        return false;
    }

    // Обновляем предыдущее значение
    prevValue = node->data;

    // Проверяем правое поддерево
    return isMonotonicIncreasing(node->right, prevValue);
}

void BinaryTree::checkMonotonicIncreasing()  {
    int prevValue = std::numeric_limits<int>::min();
    if (isMonotonicIncreasing(root, prevValue)) {
        std::cout << "nil" << std::endl;
    }
}

void BinaryTree::insert(int value){
    root = insertRecursive(root, value);
}

void BinaryTree::updateValue(int oldValue, int newValue) {
    TreeNode* nodeToUpdate = findNode(root, oldValue);

    if (nodeToUpdate != nullptr) {
        nodeToUpdate->data = newValue;
    } else {
        std::cout << "Node with key " << oldValue << " not found." << std::endl;
    }
}

TreeNode *BinaryTree::insertRecursive(TreeNode *node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    if (value < node->data) {
        node->left = insertRecursive(node->left, value);
    } else if (value > node->data) {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

TreeNode *BinaryTree::findNode(TreeNode *node, int value) {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return findNode(node->left, value);
    } else {
        return findNode(node->right, value);
    }
}


