struct Item {
    int value;
    Item *prev = nullptr;
    Item *next = nullptr;
};

class List {
private:
    Item *head = nullptr;
    Item *tail = nullptr;
    int _len = 0;
public:
    List() = default;
    List(int *arr, int len);
    ~List();

    int length();
    void print();

    void pushToIndex(int value, int index);
    void pushToHead(int value);
    void pushToEnd(int value);
    void pushAfterNum(int value, int after);

    void removeToIndex(int index);
    void removeToHead();
    void removeToEnd();
    void removeAfterNum(int after);
    void removeItem(int value);
    void clear();

    void replaceToIndex(int value, int index);
    bool isInclude(int value);
    int count(int value);
    int getToIndex(int index);
};
