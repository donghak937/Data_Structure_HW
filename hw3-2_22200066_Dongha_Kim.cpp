// 22200066 김동하 데이터구조 01분반 3-2번 과제

#include <iostream>
#include <string>
#define SIZE 10

using namespace std;

class operStack {
    char s[SIZE];
    int top = 0;
public:
    operStack();
    void push(char x);
    char pop();
    bool isEmpty();
    char top_element();
};

operStack::operStack() {
    top = 0;
}

void operStack::push(char x) {
    s[top] = x;
    top++;
}

char operStack::pop() {
    top--;
    return s[top];

}
bool operStack::isEmpty() {
    return (top == 0);

}

char operStack::top_element() {
    return s[top - 1];
}

int main() {
    string input;
    operStack stack1;
    bool isPali = true;

    cin >> input;
    int size = input.size();

    for (int i = 0; i < size; i++) {
        if (i < input.size() / 2) {
            stack1.push(input[i]);
        }
        else if (size % 2 == 1) {
            if (i > size / 2) {
                if (input[i] != stack1.pop()) {
                    isPali = false;
                    break;
                }
            }
        }
        else if (size % 2 == 0) {
            if (i >= size / 2) {
                if (input[i] != stack1.pop()) {
                    isPali = false;
                    break;
                }
            }
        }

    }
    if (isPali) cout << "Yes, it’s a palindrome.";
    else cout << "No, it’s a not palindrome.";
}