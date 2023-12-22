#include "StringTree.h"

void StringTree::insert(const string& word, int count, STNode *node) {  // Добавление элемента
    if (node == nullptr) node = head;  // Если это начало рекурсии, то она идет с корня
    if (node == nullptr) {  // Если корень пустой, то корень надо создать
        head = new STNode{word, count};
        length = word.size();
        return;
    }
    int res = node->word.compare(word);  // Если будет < 0, значит слово, переданное В функцию, больше того, что в узле
    if (res < 0) {  // Наше слово больше чем в узле
        if (node->right != nullptr) insert(word, count, node->right);  // Если правая ветка сущ. то идем рекурсивно направо
        else {  // Если нет, то создаем правый лист
            node->right = new STNode{word, count};
            if (word.size() > length) length = word.size() / 2 + 1;
        }
    } else if (res > 0) {  // Наше слово меньше чем в узле
        if (node->left != nullptr) insert(word, count, node->left);  // Если левая ветка сущ. то идем рекурсивно налево
        else {  // Если нет, то создаем левый лист
            node->left = new STNode{word, count};
            if (word.size() > length) length = word.size() / 2 + 1;
        }
    } else {  // Наше слово совпадает с тем, что в узле
        node->count += count;
    }
}

int StringTree::remove(const string &word, STNode *node, STNode *prev, int side, bool isHead) {
    if (isHead) node = head;  // Если это начало рекурсии, то она идет с корня
    if (node == nullptr) return 0;  // Если элемента тупо нет, то возвращаем 0
    int res = node->word.compare(word);  // Если будет < 0, значит слово, переданное В функцию, больше того, что в узле
    if (res < 0) {  // Наше слово больше чем в узле
        return remove(word, node->right, node, 1, false);  // Рекурсивно идем направо
    } else if (res > 0) {  // Наше слово меньше чем в узле
        return remove(word, node->left, node, -1, false);  // Рекурсивно идем налево
    } else {  // Слово совпадает
        int count = node->count;  // Запоминаем удаляемое количество
        if (node->right == nullptr && node->left == nullptr) {  // Если листьев/ветвей нет
            if (side == 0) head = nullptr;  // Если это корень
            else side > 0 ? prev->right = nullptr : prev->left = nullptr;  // подтираем ссылку на удаляемый элемент
            delete node;
        } else if (node->right == nullptr || node->left == nullptr) {  // Если лист/ветка только одна
            STNode *rmnode = node->right != nullptr ? node->right : node->left;
            *node = *(node->right != nullptr ? node->right : node->left);  // копируем ее в удаляемую ноду
            delete rmnode;  // удаляем оригинал
        } else {  // Если у элемента две ветви/листа
            hardRemove(node->left, node, node);  // Используем специальную рекурсивную функцию удаления
        }
        return count;
    }
}

void StringTree::hardRemove(STNode *node, STNode *prev, STNode *rmnode) {
    if (node->right != nullptr) hardRemove(node->right, node, rmnode);  // Идем к самому правому элементу
    else {
        rmnode->word = node->word;  // копируем значения правого элемента
        rmnode->count = node->count;
        if (node->left != nullptr) {  // Если есть ответвления влево, то переносим левую часть повыше
            STNode *leftNode = node->left;
            *node = *leftNode;
            delete leftNode;
        } else {  // если веток/листьев нет, то тупа удаляем
            prev->right == node ? prev->right = nullptr : prev->left = nullptr;
            delete node;
        }
    }
}

bool in(vector<int> &nums, int number) {
    for (int num : nums) if (num == number) return true;
    return false;
}

void StringTree::printTree(STNode *node, int level, int side, vector<int> nums) {
    if (node == nullptr) {  // Если не задано, то задаем на корень
        if (head == nullptr) return;
        node = head;
    }

    if (node->right != nullptr) {
        if (side < 0) nums.push_back(level);
        printTree(node->right, level + 1, 1, nums);
        if (side < 0) nums.pop_back();
    }

    for (int i = 0; i < level * (length + 3) - 2; ++i) {
        if ((i + 2) % (length + 3)) cout << " ";
        else if (in(nums, (i + 2) / (length + 3)) && level != nums.back()) cout << "|";
        else cout << " ";
    }
    if (level > 0) {
        if (side > 0) cout << "|-";
        if (side < 0) cout << "|-";
    }
    cout << node->word;
    if (node->right != nullptr || node->left != nullptr) {
        for (int i = 0; i < length - (node->word.length() / 2) + 1; ++i) cout << "-";
        if (node->right != nullptr && node->left != nullptr) cout << "-\n";
        else if (node->right != nullptr) cout << "|\n";
        else cout << "|\n";
    } else cout << endl;

    if (node->left != nullptr) {
        if (side > 0) nums.push_back(level);
        printTree(node->left, level + 1, -1, nums);
        if (side > 0) nums.pop_back();
    }
}

void StringTree::printCount(STNode *node, bool isHead) {
    if (isHead) node = head;
    if (node == nullptr) return;
    printCount(node->left, false);
    cout << node->word << ": " << node->count << endl;
    printCount(node->right, false);
}