#include <iostream>
using namespace std;

struct StackNode {
    char value;
    StackNode* next = nullptr;
};

class Stack {
private:
    StackNode* head = nullptr;
    int length = 0;
public:
    ~Stack();
    int getLength() const;
    void push(char value);
    char peek() const;
    char pop();
    void clear();
    bool include(char value) const;
    int count(char value) const;
};
