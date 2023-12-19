#pragma once
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& value, Node* prevNode = nullptr, Node* nextNode = nullptr)
            : data(value), prev(prevNode), next(nextNode) {}
};

template <typename T>
class MyList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    class Iterator {
    private:
        Node<T>* current;
        const MyList<T>* myList;

    public:
        Iterator(Node<T>* node, const MyList<T>* list) : current(node), myList(list) {}

        Iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        Iterator& operator--() {
            if (current) {
                current = current->prev;
            } else
                current = myList->tail;
            return *this;
        }

        T& operator*() const {
            return current->data;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        friend MyList<T>::Iterator MyList<T>::insert(const Iterator& it, const T& value);
        friend MyList<T>::Iterator MyList<T>::erase(const Iterator& it);
    };

    MyList() : head(nullptr), tail(nullptr) {}

    Iterator begin() const {
        return Iterator(head, this);
    }

    Iterator end() const {
        return Iterator(nullptr, this);
    }

    Iterator insert(const Iterator& it, const T& value);

    Iterator erase(const Iterator& it);

    // Метод слияния двух списков
    void merge(const MyList<T>& otherList);

    // Метод слияния двух упорядоченных списков
    void mergeOrdered(const MyList<T>& list1, const MyList<T>& list2);

    ~MyList();

    template<typename D>
    friend std::ostream &operator<<(std::ostream &stream, const MyList<D> list) {
        for (auto it = list.begin(); it != list.end(); ++it) {
            stream << *it << ' ';
        }
        return stream;
    }

    template<typename D>
    friend std::istream &operator>>(std::istream &stream, MyList<D> list);
};

template<typename D>
std::istream &operator>>(std::istream &stream, MyList<D> list) {
    D val;
    stream >> val;
    list.insert(list.end(), val);
    return stream;
}

template<typename T>
MyList<T>::~MyList() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void MyList<T>::mergeOrdered(const MyList<T> &list1, const MyList<T> &list2)  {
    Iterator it1 = list1.begin();
    Iterator it2 = list2.begin();

    while (it1 != list1.end() && it2 != list2.end()) {
        if (*it1 < *it2) {
            insert(end(), *it1);
            ++it1;
        } else {
            insert(end(), *it2);
            ++it2;
        }
    }

    // Добавляем оставшиеся элементы из первого списка
    while (it1 != list1.end()) {
        insert(end(), *it1);
        ++it1;
    }

    // Добавляем оставшиеся элементы из второго списка
    while (it2 != list2.end()) {
        insert(end(), *it2);
        ++it2;
    }
}

template<typename T>
void MyList<T>::merge(const MyList<T> &otherList) {
    for (Iterator it = otherList.begin(); it != otherList.end(); ++it) {
        insert(end(), *it);
    }
}

template <typename T>
MyList<T>::Iterator MyList<T>::insert(const Iterator& it, const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!it.current) {
        newNode->prev = tail;
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    } else {
        newNode->prev = it.current->prev;
        newNode->next = it.current;
        if (it.current->prev) {
            it.current->prev->next = newNode;
        } else {
            head = newNode;
        }
        it.current->prev = newNode;
    }

    return Iterator(newNode, this);
}

template <typename T>
MyList<T>::Iterator MyList<T>::erase(const Iterator& it) {
    if (it.current) {
        Node<T>* nextNode = it.current->next;
        if (it.current->prev) {
            it.current->prev->next = nextNode;
        } else {
            head = nextNode;
        }
        if (nextNode) {
            nextNode->prev = it.current->prev;
        } else {
            tail = it.current->prev;
        }
        delete it.current;

        return Iterator(nextNode, this);
    }

    return it;
}
