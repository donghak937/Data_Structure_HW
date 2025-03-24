// 22200066 김동하 데이터구조 01분반 2번 과제

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


bool is_operand(char ch) {
    if (ch >= '!' && ch <= '/') return false;
    else return true;
}

int get_precedence(char op) {
    if (op == '$' || op == '(') return 0;
    else if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/' || op == '%') return 2;
    return -1;
}


int main() {
    string infix;
    string postfix;
    operStack stack1;

    cin >> infix;
    infix += '$';
    for (int i = 0; i < infix.size(); i++) {
        if (is_operand(infix[i])) {
            postfix += infix[i];
        }
        else if (i == infix.size() - 1) {
            while (stack1.isEmpty() == false) {
                postfix += stack1.pop();
            }
        }
        else if (stack1.isEmpty()) {
            stack1.push(infix[i]);
        }
        else if (get_precedence(infix[i]) == 0) {
            stack1.push(infix[i]);
        }
        else if (get_precedence(infix[i]) == -1) {
            while (get_precedence(stack1.top_element()) != 0) {
                postfix += stack1.pop();
            } 
            stack1.pop();
        }
        else if (get_precedence(stack1.top_element()) >= get_precedence(infix[i])) {
            while (get_precedence(stack1.top_element()) >= get_precedence(infix[i])) {
                postfix += stack1.pop();
            }
            stack1.push(infix[i]);
        }
        else stack1.push(infix[i]);
        
 
        
    }
    cout << postfix;

}
