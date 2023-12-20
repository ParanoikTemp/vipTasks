#pragma once
#include <iostream>

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* node, int key);

    TreeNode *getMinNode(TreeNode *node);

    void *delMinNode(TreeNode *node);

    void print(TreeNode *node, int level, int side);

    TreeNode *find(TreeNode *node, int key);

public:
    BinaryTree() : root(nullptr) {}

    void insert(int key);

    void removeNode(TreeNode* node);

    void printTree();

    TreeNode *findElem(int key);
};
