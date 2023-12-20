#include "BinaryTree.h"

TreeNode *BinaryTree::insertRecursive(TreeNode *node, int key)
{
    if (!node) {
        return new TreeNode(key);
    }

    if (key < node->key) {
        node->left = insertRecursive(node->left, key);
    } else if (key > node->key) {
        node->right = insertRecursive(node->right, key);
    }

    return node;
}

TreeNode *BinaryTree::getMinNode(TreeNode *node) {
    if (node->left != nullptr)
        return getMinNode(node->left);
    else
        return node;
}

void *BinaryTree::delMinNode(TreeNode *node) {
    if (node->left->left == nullptr && node->left->right == nullptr) {
        delete node->left;
        node->left = nullptr;
    } else
        delMinNode(node->left);
}

void BinaryTree::print(TreeNode *node, int level, int side) {
    if (node->right != nullptr)
        print(node->right, level + 1, 1);
    for (int i = 0; i < level; ++i)
        std::cout << "    ";
    if (side == 1)
        std::cout << '/';
    else if (side == -1)
        std::cout << '\\';
    else
        std::cout << '[';
    std::cout << node->key << '\n';
    if (node->left != nullptr)
        print(node->left, level + 1, -1);

}

TreeNode *BinaryTree::find(TreeNode *node, int key) {
    if (node == nullptr)
        return nullptr;
    if (key == node->key)
        return node;
    if (key > node->key)
        return find(node->right, key);
    else
        return find(node->left, key);
}

void BinaryTree::insert(int key) {
    if (!root) {
        root = new TreeNode(key);
    }
    insertRecursive(root, key);
}

void BinaryTree::removeNode(TreeNode *node) {
    TreeNode* min_node = getMinNode(node->right);
    node->key = min_node->key;
    if (min_node->right != nullptr) {
        TreeNode *temp = min_node->right;
        min_node = min_node->right;
        delete temp;
    } else
        delMinNode(node->right);
}

void BinaryTree::printTree() {
    print(root, 0, 0);
}

TreeNode *BinaryTree::findElem(int key) {
    return find(root, key);
}
