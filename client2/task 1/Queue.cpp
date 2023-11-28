#include "Queue.h"

Queue::~Queue() {
    clear();
}

int Queue::getLength() const {
    return length;
}

void Queue::enqueue(const char value) {
    length += 1;
    if (length == 1) head = tail = new QueueNode{value};
    else {
        head = new QueueNode{value, head};
        head->next->prev = head;
    }
}

char Queue::dequeue() {
    length -= 1;
    char value = tail->value;
    QueueNode* rem = tail;
    if (length == 0)
        head = tail = nullptr;
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete rem;
    return value;
}

char Queue::peek() const {
    return tail->value;
}

void Queue::clear() {
    while (length > 0) dequeue();
}

bool Queue::include(const char value) const {
    for (QueueNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) return true;
    return false;
}
int Queue::count(const char value) const {
    int cnt = 0;
    for (QueueNode* node = head; node != nullptr; node = node->next)
        if (node->value == value) ++cnt;
    return cnt;
}
