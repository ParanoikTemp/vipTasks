#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>

using namespace std;

struct TreeNode {
    char data;
    int count;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), count(1), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* addNode(TreeNode* node, char value);
    TreeNode* findMin(TreeNode* node);
    TreeNode* removeNode(TreeNode* node, char value);
    void printTree(TreeNode* node, int indent = 0, char branchSymbol = ' ');
    void printPostorder(TreeNode* node);
    TreeNode* removeDuplicates(TreeNode* node);
public:
    BinaryTree() : root(nullptr) {}
    void add(char value);
    void displayTree();
    void removeElement(char value);
    void displayPostorder();
    void removeDuplicates();
};
