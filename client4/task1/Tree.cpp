#include "Tree.h"

// Метод для добавления нового элемента в дерево
void BinaryTree::addNode(int val) {
    if (head == nullptr) {
        head = new TreeNode(val);
        cursor = head; // Устанавливаем курсор на корень
    } else {
        addNodeRecursive(val, head);
    }
}

void BinaryTree::printTree() const {
    printTreeRecursive(head, 0);
    std::cout << std::endl;
}

// Метод для перемещения курсора на корень дерева
void BinaryTree::moveToRoot() {
    cursor = head;
}

// Метод для перемещения курсора влево (если возможно)
void BinaryTree::moveToLeft() {
    if (canMoveToLeft()) {
        cursor = cursor->left;
    }
}

// Метод для перемещения курсора вправо (если возможно)
void BinaryTree::moveToRight() {
    if (canMoveToRight()) {
        cursor = cursor->right;
    }
}

// Метод для перемещения курсора на родителя (если возможно)
void BinaryTree::moveToParent() {
    if (canMoveToParent()) {
        cursor = cursor->parent;
    }
}

// Метод для получения значения, на которое указывает курсор
int BinaryTree::getCursorValue() const {
    return (cursor != nullptr) ? cursor->value : -1; // Можно выбрать другое значение по умолчанию
}

// Метод для получения ссылки на узел, на который указывает курсор
BinaryTree::TreeNode* BinaryTree::getCursorNode() const {
    return cursor;
}

// Методы, проверяющие, можно ли двигаться в соответствующем направлении
bool BinaryTree::canMoveToLeft() const {
    return (cursor != nullptr && cursor->left != nullptr);
}

bool BinaryTree::canMoveToRight() const {
    return (cursor != nullptr && cursor->right != nullptr);
}

bool BinaryTree::canMoveToParent() const {
    return (cursor != nullptr && cursor->parent != nullptr);
}

// Рекурсивная функция для добавления нового элемента
void BinaryTree::addNodeRecursive(int val, TreeNode* currentNode) {
    if (val < currentNode->value) {
        if (currentNode->left == nullptr) {
            currentNode->left = new TreeNode(val);
            currentNode->left->parent = currentNode;
        } else {
            addNodeRecursive(val, currentNode->left);
        }
    } else if (val > currentNode->value) {
        if (currentNode->right == nullptr) {
            currentNode->right = new TreeNode(val);
            currentNode->right->parent = currentNode;
        } else {
            addNodeRecursive(val, currentNode->right);
        }
    }
    // Обратите внимание, что здесь нет блока else для обработки случая, когда значение уже существует в дереве
}

// Рекурсивная функция для печати дерева (in-order traversal)
void BinaryTree::printTreeRecursive(const TreeNode* currentNode, int level) const {
    if (currentNode != nullptr) {
        printTreeRecursive(currentNode->right, level + 1);

        for (int i = 0; i < level; ++i) {
            std::cout << "    "; // 4 пробела для каждого уровня
        }
        if (currentNode->parent != nullptr) {
            if (currentNode == currentNode->parent->left)
                std::cout << '\\';
            else if (currentNode == currentNode->parent->right)
                std::cout << '/';
        }
        std::cout << currentNode->value << std::endl;

        printTreeRecursive(currentNode->left, level + 1);
    }
}

int BinaryTree::TreeNode::getLevel() const {
    int level = 0;
    const TreeNode* currentNode = this;

    while (currentNode->parent != nullptr) {
        currentNode = currentNode->parent;
        ++level;
    }

    return level;
}
