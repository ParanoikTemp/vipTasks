#pragma once
#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int value)
            : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // Рекурсивная функция для добавления узла в дерево
    void insertRecursive(TreeNode *current, int value, TreeNode *parent, int num);

    // Рекурсивная функция для установки значения parent
    void setParentRecursively(TreeNode* current);

    // Простой метод для вывода дерева в прямом порядке
    void printInOrder(TreeNode* current) const;

    TreeNode* findMin(TreeNode* node) const;

    void deleteElement(TreeNode* node, int value);

    void printTree(TreeNode* node, int level);
public:
    BinaryTree() : root(nullptr) {}

    // Метод для добавления элемента в дерево
    void insert(int value);

    // Метод для установки значения parent для всех узлов
    void setParent();

    // Метод для вывода дерева в прямом порядке
    void printInOrder() const;

    void deleteElement(int value);

    void printTree();
};
