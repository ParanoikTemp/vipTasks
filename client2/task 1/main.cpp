#include <string>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {
    Queue chars1;
    Stack brackets, chars2;
    string stroke = "ABC{D(E)F}KLM{Z[H]O}BN";
    for (char c: stroke) {
        if (c == '{' || c == '[' || c == '(')
            brackets.push(c);
        else if (c == '}' || c == ']' || c == ')')
            brackets.pop();
        else if (brackets.getLength())
            chars2.push(c);
        else
            chars1.enqueue(c);
    }
    string new_stroke;
    while (chars1.getLength())
        new_stroke += chars1.dequeue();
    while (chars2.getLength())
        new_stroke += chars2.pop();

    cout << new_stroke;
    return 0;
}
