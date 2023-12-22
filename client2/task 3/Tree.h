#include <iostream>
#include <limits>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // Приватная рекурсивная функция для проверки монотонного возрастания
    bool isMonotonicIncreasing(TreeNode* node, int& prevValue);

    // Приватная рекурсивная функция для добавления элемента в дерево
    TreeNode* insertRecursive(TreeNode* node, int value);


    TreeNode* findNode(TreeNode* node, int value);

public:
    BinaryTree() : root(nullptr) {}

    // Публичная функция для проверки монотонного возрастания
    void checkMonotonicIncreasing();

    // Публичная функция для добавления элемента в дерево
    void insert(int value);

    void updateValue(int oldValue, int newValue);
};