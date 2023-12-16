#include "BinaryTree.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    BinaryTree tree;
    string text;
    getline(cin, text);
    for (char c: text)
        tree.add(c);

    tree.displayTree();
    tree.removeDuplicates();
    cout << "\n\n";
    tree.displayTree();
    cout << "\n\n";
    tree.displayPostorder();
    return 0;
}
