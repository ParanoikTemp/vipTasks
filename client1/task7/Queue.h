#pragma once
#include <ostream>

using namespace std;

template <typename Type>
struct QueueNode {
    Type value;
    QueueNode<Type>* next = nullptr;
    QueueNode<Type>* prev = nullptr;
};

template <typename Type>
class Queue {
private:
    QueueNode<Type>* head = nullptr;
    QueueNode<Type>* tail = nullptr;
    int length = 0;
public:
    ~Queue();
    int getLength() const;
    void enqueue(const Type value);
    Type dequeue();
    Type peek() const;
    void clear();
    bool include(const Type value) const;
    int count(const Type value) const;
};

template <typename Type>
Queue<Type>::~Queue() {
    clear();
}

template <typename Type>
int Queue<Type>::getLength() const {
    return length;
}

template <typename Type>
void Queue<Type>::enqueue(const Type value) {
    length += 1;
    if (length == 1) head = tail = new QueueNode<Type>{ value };
    else {
        head = new QueueNode<Type>{ value, head };
        head->next->prev = head;
    }
}

template <typename Type>
Type Queue<Type>::dequeue() {
    length -= 1;
    Type value = tail->value;
    QueueNode<Type>* rem = tail;
    if (length == 0)
        head = tail = nullptr;
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete rem;
    return value;
}

template <typename Type>
Type Queue<Type>::peek() const {
    return tail->value;
}

template <typename Type>
void Queue<Type>::clear() {
    while (length > 0) dequeue();
}

template <typename Type>
bool Queue<Type>::include(const Type value) const {
    for (QueueNode<Type>* node = head; node != nullptr; node = node->next)
        if (node->value == value) return true;
    return false;
}

template <typename Type>
int Queue<Type>::count(const Type value) const {
    int cnt = 0;
    for (QueueNode<Type>* node = head; node != nullptr; node = node->next)
        if (node->value == value) ++cnt;
    return cnt;
}

class Car {
private:
    string model;
    int cylinders;
    float capacity;
public:
    friend ostream &operator<<(ostream &stream, const Car &car) {
        stream << "Car: [brand: " << car.model << ", cylinders: " << car.cylinders << ", capacity: " << car.capacity << "]";
        return stream;
    }
    Car(string _model, int _cylinders, float _capacity) : model(_model), cylinders(_cylinders), capacity(_capacity) {}
};
