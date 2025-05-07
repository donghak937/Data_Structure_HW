// 22200066 김동하 데이터구조 01분반 3-1번 과제

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


int is_parentheses(char ch) {
    if (ch == '(' || ch == '{' || ch == '[') return 0;
    else if (ch == ')' || ch == '}' || ch == ']') return 1;
    else return 2;
}

char match_parentheses(char ch) {
    if (ch == '(') return ')';
    else if (ch == '{') return '}';
    else if (ch == '[') return ']';
    else if (ch == ')') return '(';
    else if (ch == '}') return '{';
    else return '[';
}



int main() {
    string input;
    bool isVaild = true;
    char popedChar;
    char errorChar;
    bool extra = false;
    operStack stack1;

    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        if (is_parentheses(input[i]) == 0) {
            stack1.push(input[i]);
        }
        else if (is_parentheses(input[i]) == 1) {
            if (stack1.isEmpty()) {
                extra = true;
                popedChar = input[i];
                break;
            }
            popedChar = match_parentheses(stack1.pop());
            if (input[i] != popedChar) {
                isVaild = false;
                break;
            }
        }
        else continue;
    }
    if (extra) cout << "Error: An extra parenthesis ‘" << popedChar << "’ is found.";
    else if (isVaild) cout << "It’s a normal expression";
    else if (isVaild == false) cout << "Error: mis-matched parenthesis, ‘"<< popedChar << "’ is expected.";

}
