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

TreeNode *BinaryTree::findMin(TreeNode *node) const {
    if (node->left == nullptr)
        return node;
    return findMin(node->left);
}

void BinaryTree::deleteElement(int value) {
    deleteElement(root, value);
}

void BinaryTree::deleteElement(TreeNode *node, int value) {
    if (node->data == value) {
        if (node->right == nullptr && node->left == nullptr) {
            if (node == root) {
                delete node;
                root = nullptr;
                return;
            }
            if (node->parent->right == node)
                node->parent->right = nullptr;
            else
                node->parent->left = nullptr;
            delete node;
            return;
        }
        if (node->right == nullptr && node->left != nullptr || node->left == nullptr && node->right != nullptr) {
            TreeNode *remNode = (node->right != nullptr ? node->right : node->left);
            node->data = remNode->data;
            node->right = remNode->right;
            node->left = remNode->left;
            if (node->left != nullptr)
                node->left->parent = node;
            if (node->right != nullptr)
                node->right->parent = node;
            delete remNode;
            return;
        }
        if (node->right != nullptr && node->left != nullptr) {
            TreeNode *minNode = findMin(node->right);
            node->data = minNode->data;
            deleteElement(minNode, minNode->data);
            return;
        }
    } else if (node->data < value)
        deleteElement(node->right, value);
    else
        deleteElement(node->left, value);
}

void BinaryTree::printTree() {
    printTree(root, 0);
}

void BinaryTree::printTree(TreeNode *node, int level) {
    if (node == nullptr)
        return;
    printTree(node->right, level + 1);
    for (int i = 0; i < level; ++i) {
        std::cout << "    ";
    }
    if (node->parent != nullptr) {
        if (node->parent->right == node)
            std::cout << '/';
        else
            std::cout << '\\';
    }
    std::cout << node->data << std::endl;
    printTree(node->left, level + 1);
}
