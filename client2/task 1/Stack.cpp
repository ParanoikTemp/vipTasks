#include "Stack.h"

Stack::~Stack() {clear();};

int Stack::getLength() const {
    return length;
}

void Stack::push(const char value) {
    head = new StackNode{value, head};
    length += 1;
}

char Stack::peek() const {
    return head->value;
}

char Stack::pop() {
    if (length > 0) {
        length -= 1;
        StackNode* rem = head;
        head = head->next;
        char value = rem->value;
        delete rem;
        return value;
    }
    return 0;
}

void Stack::clear() {
    while (length > 0) pop();
}

bool Stack::include(const char value) const {
    for (StackNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) return true;
    return false;
}

int Stack::count(const char value) const {
    int cnt = 0;
    for (StackNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) ++cnt;
    return cnt;
}
