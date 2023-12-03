#include <iostream>
#include <ostream>

template <typename T>
struct ListNode {
    T data;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
};

template <typename T>
class List;

template <typename T>
class List {
private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int length;
public:
    List();
    class Iterator {
    private:
        ListNode<T>* node;
        const List<T> &list;
    public:
        Iterator(ListNode<T>* _node, const List<T> &_list): list(_list) {
            node = _node;
        }
        Iterator(const Iterator &other) = default;
        Iterator &operator=(const Iterator &other) = default;

        Iterator operator++(int) {
            Iterator it = *this;
            if (node == nullptr)
                node = list.head;
            else
                node = node->next;
            return it;
        }
        Iterator operator--(int) {
            Iterator it = *this;
            if (node == nullptr)
                node = list.tail;
            else
                node = node->prev;
            return it;
        }
        Iterator &operator++() {
            if (node == nullptr)
                node = list.head;
            else
                node = node->next;
            return *this;
        }
        Iterator &operator--() {
            if (node == nullptr)
                node = list.tail;
            else
                node = node->prev;
            return *this;
        }
        bool operator==(const Iterator &other) const {
            return node == other.node;
        }
        bool operator!=(const Iterator &other) const {
            return node != other.node;
        }
        T& operator*() const {
            return node->data;
        }

        friend void List<T>::addItem(T item, Iterator &it);
        friend T List<T>::deleteItem(Iterator &it);
    };
    Iterator begin() const {
        return Iterator(head, *this);
    }
    Iterator end() const {
        return Iterator(nullptr, *this);
    }
    void addItem(T item, Iterator &it);
    T deleteItem(Iterator &it);

    template<typename L>
    friend std::ostream &operator<<(std::ostream &stream, const List<L> &other) {
        stream << '[';
        auto last = --other.end();
        for (auto it = other.begin(); it != last; ++it) {
            stream << *it << ", ";
        }
        stream << *last << ']';
        return stream;
    }

    template<typename L>
    friend std::istream &operator>>(std::istream &stream, List<L> &other);
};

template<typename L>
std::istream &operator>>(std::istream &stream, List<L> &other) {
    int count;
    stream >> count;
    auto end = other.end();
    L val;
    for (int i = 0; i < count; ++i) {
        stream >> val;
        other.addItem(val, end);
        ++end;
    }
    return stream;
}

template<typename T>
T List<T>::deleteItem(List::Iterator &it) {
    T val = it.node->data;
    ListNode<T> *remNode = it.node;
    if (it.node == head) {
        head = head->next;
        it.node = head;
    } else if(it.node == tail) {
        tail = tail->prev;
        it.node = tail;
    } else {
        it.node->next->prev = it.node->prev;
        it.node->prev->next = it.node->next;
        it.node = it.node->next;
    }
    delete remNode;
    return val;
}

template<typename T>
void List<T>::addItem(T item, List::Iterator &it) {
    if (it == end()) {
        if (length == 0) {
            it.node = head = tail = new ListNode<T>{item};
        } else {
            it.node = tail = new ListNode<T>{item, tail};
            tail->prev->next = tail;
        }
    } else {
        if (it == begin()) {
            it.node = head = new ListNode<T>{item, nullptr, head};
            head->next->prev = head;
        } else {
            it.node = new ListNode<T>{item, it.node->prev, it.node};
            it.node->next->prev = it.node;
            it.node->prev->next = it.node;
        }
    }
    length++;
}

template<typename T>
List<T>::List() {
    head = nullptr;
    length = 0;
}
