struct QueueNode {
    char value;
    QueueNode* next = nullptr;
    QueueNode* prev = nullptr;
};

class Queue {
private:
    QueueNode* head = nullptr;
    QueueNode* tail = nullptr;
    int length = 0;
public:
    ~Queue();
    int getLength() const;
    void enqueue(const char value);
    char dequeue();
    char peek() const;
    void clear();
    bool include(const char value) const;
    int count(const char value) const;
};
