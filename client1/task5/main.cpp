#include "Stack.h"
#include <string>
#include <fstream>

using namespace std;

int main() {
    Stack brackets;
    string text;
    string filepath = "C:\\cpp_files\\task17\\text.txt";
    ifstream file(filepath);
    if (file.is_open()) {
        file >> text;
        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == '(') {
                for (int j = i + 1; j < text.length(); ++j) {
                    if (text[j] == '(')
                        brackets.push('(');
                    else if (text[j] == ')' && brackets.getLength())
                        brackets.pop();
                    else if (text[j] == ')') {
                        cout << i + 1 << ' ' << j + 1 << "; ";
                        break;
                    }
                }
            }
        }
    }
    file.close();
    return 0;
}
