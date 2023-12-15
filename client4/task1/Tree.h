#pragma once
#include <iostream>

class BinaryTree {
private:
    struct TreeNode {
        int value;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;

        TreeNode(int val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}

        int getLevel() const;
    };

    TreeNode* head;   // Указатель на корень дерева
    TreeNode* cursor; // Курсор, изначально указывает на корень

public:
    BinaryTree() : head(nullptr), cursor(nullptr) {}

    // Метод для добавления нового элемента в дерево
    void addNode(int val);

    void printTree() const;
    // Метод для перемещения курсора на корень дерева
    void moveToRoot();

    // Метод для перемещения курсора влево (если возможно)
    void moveToLeft();

    // Метод для перемещения курсора вправо (если возможно)
    void moveToRight();

    // Метод для перемещения курсора на родителя (если возможно)
    void moveToParent();

    // Метод для получения значения, на которое указывает курсор
    int getCursorValue() const;
    // Метод для получения ссылки на узел, на который указывает курсор
    TreeNode* getCursorNode() const;

    // Методы, проверяющие, можно ли двигаться в соответствующем направлении
    bool canMoveToLeft() const;

    bool canMoveToRight() const;

    bool canMoveToParent() const;

    // Рекурсивная функция для добавления нового элемента
    void addNodeRecursive(int val, TreeNode* currentNode);

    // Рекурсивная функция для печати дерева (in-order traversal)
    void printTreeRecursive(const TreeNode* currentNode, int level) const;
};
