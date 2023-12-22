#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::string, std::cout, std::endl, std::vector;


// Справа те элементы, что больше. Слева - меньше.
struct STNode {
    string word;
    int count = 1;
    STNode *right = nullptr;
    STNode *left = nullptr;
    ~STNode() {
        right = nullptr;
        left = nullptr;
        delete right;
        delete left;
    }

};

class StringTree {
private:
    STNode *head = nullptr;
    int length = 0;
    void hardRemove(STNode *node, STNode *prev, STNode *rmnode);
public:
    void insert(const string& word, int count = 1, STNode *node = nullptr);
    int remove(const string& word, STNode *node = nullptr, STNode *prev = nullptr, int side = 0, bool isHead = true);
    void printTree(STNode *node = nullptr, int level = 0, int side = 0, vector<int> nums = vector<int>());
    void printCount(STNode *node = nullptr, bool isHead = true);
};