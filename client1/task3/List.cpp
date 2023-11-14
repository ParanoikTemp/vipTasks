#include "List.h"
#include <iostream>

using std::cout;

List::List(int *arr, int len) {
    if (len == 0) return;
    head = tail = new Item{arr[0]};
    Item *node = head;
    for (int i = 1; i < len; ++i) {
        node->next = new Item{arr[i], node};
        node = node->next;
        tail = node;
    }
}

int List::length() {
    return _len;
}

void List::pushToIndex(int value, int index) {
    if (index < 0 || index > _len) return;
    _len += 1;
    if (_len == 1) {
        head = tail = new Item{value};
        return;
    }
    if (index == _len - 1) {
        tail->next = new Item{value, tail};
        tail = tail->next;
        return;
    }
    if (index == 0) {
        head->prev = new Item{value, nullptr, head};
        head = head->prev;
        return;
    }
    Item *node = head;
    for (int i = 0; i < index - 1; ++i) {
        node = node->next;
    }
    node->next = new Item{value, node, node->next};
    node->next->next->prev = node->next;
}

void List::pushToHead(int value) {
    pushToIndex(value, 0);
}

void List::pushToEnd(int value) {
    pushToIndex(value, _len);
}

void List::pushAfterNum(int value, int after) {
    Item *node = head;
    for (int i = 0; i < _len; ++i) {
        if (node->value == after) {
            pushToIndex(value, i + 1);
            ++i;
            node = node->next;
        }
        node = node->next;
    }
}

void List::print() {
    cout << "[";
    Item *node = head;
    for (int i = 0; i < _len - 1; ++i) {
        cout << node->value << ", ";
        node = node->next;
    }
    if (node != nullptr) cout << node->value;
    cout  << ']';
}

void List::removeToIndex(int index) {
    if (index < 0 || index >= _len) return;
    _len -= 1;
    Item *rem = nullptr;
    if (_len == 0) {
        head = tail = nullptr;
    } else if (index == 0) {
        rem = head;
        head = head->next;
        head->prev = nullptr;
        delete rem;
    } else if (index == _len) {
        rem = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete rem;
    } else {
        rem = head;
        for (int i = 0; i < index; ++i) {
            rem = rem->next;
        }
        rem->next->prev = rem->prev;
        rem->prev->next = rem->next;
        delete rem;
    }
}

void List::removeToHead() {
    removeToIndex(0);
}

void List::removeToEnd() {
    removeToIndex(_len - 1);
}

void List::removeAfterNum(int after) {
    Item *node = head;
    for (int i = 0; i < _len; ++i) {
        if (node->value == after) removeToIndex(i + 1);
        node = node->next;
    }
}

void List::removeItem(int value) {
    Item *node = head;
    for (int i = 0; i < _len; ++i) {
        if (node->value == value) {
            removeToIndex(i);
            return;
        }
        node = node->next;
    }
}

void List::clear() {
    while (_len > 0) removeToIndex(0);
}

List::~List() {
    clear();
}

void List::replaceToIndex(int value, int index) {
    Item *node = head;
    for (int i = 0; i < index; ++i) node = node->next;
    node->value = value;
}

bool List::isInclude(int value) {
    for (Item *node = head; node != nullptr; node = node->next)
        if (node->value == value) return true;
    return false;
}

int List::count(int value) {
    int cnt = 0;
    for (Item *node = head; node != nullptr; node = node->next)
        if (node->value == value) ++cnt;
    return cnt;
}

int List::getToIndex(int index) {
    Item *node = head;
    for (int i = 0; i < index; ++i) node = node->next;
    return node->value;
}

