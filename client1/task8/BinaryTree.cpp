#include "BinaryTree.h"

TreeNode* BinaryTree::addNode(TreeNode* node, char value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    if (value == node->data) {
        node->count++;
    } else if (value < node->data) {
        node->left = addNode(node->left, value);
    } else {
        node->right = addNode(node->right, value);
    }

    return node;
}

TreeNode* BinaryTree::findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode* BinaryTree::removeNode(TreeNode* node, char value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = removeNode(node->left, value);
    } else if (value > node->data) {
        node->right = removeNode(node->right, value);
    } else {
        // Удаляем узел
        if (node->left == nullptr) {
            TreeNode *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode *temp = node->left;
            delete node;
            return temp;
        }

        TreeNode *temp = findMin(node->right);
        node->data = temp->data;
        node->count = temp->count;
        node->right = removeNode(node->right, temp->data);
    }

    return node;
}

void BinaryTree::printTree(TreeNode* node, int indent, char branchSymbol) {
    if (node != nullptr) {
        printTree(node->right, indent + 4, '/');

        if (node->count > 1) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
        }

        std::cout << std::setw(indent) << branchSymbol << node->data << " (Count: " << node->count << ")";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

        std::cout << std::endl;

        printTree(node->left, indent + 4, '\\');
    }
}

void BinaryTree::printPostorder(TreeNode* node) {
    if (node != nullptr) {
        printPostorder(node->left);
        printPostorder(node->right);
        std::cout << node->data << " ";
    }
}

TreeNode* BinaryTree::removeDuplicates(TreeNode* node) {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->count > 1) {
        node = removeNode(node, node->data);
    }

    // Process the left subtree
    node->right = removeDuplicates(node->right);
    node->left = removeDuplicates(node->left);

    return node;
}

void BinaryTree::add(char value) {
    root = addNode(root, value);
}

void BinaryTree::displayTree() {
    printTree(root);
}

void BinaryTree::removeElement(char value) {
    root = removeNode(root, value);
}

void BinaryTree::displayPostorder() {
    printPostorder(root);
    std::cout << std::endl;
}

void BinaryTree::removeDuplicates() {
    root = removeDuplicates(root);
}
