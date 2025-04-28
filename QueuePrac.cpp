#include <iostream>
using namespace std;

class QueuePrac
{
private:
    int front;
    int rear;
    int size;
    int* q;
public:
    QueuePrac(int s);
    ~QueuePrac();
    void insert_q(int a);
    int delete_q();
    bool is_full();
    bool is_empty();
    void printAll();
};

QueuePrac::QueuePrac(int s) {
    size = s;
    rear = 0;
    front = 0;
    q = new int[s];
}

QueuePrac::~QueuePrac() {
}

void QueuePrac::insert_q(int a) {
    if (is_full()) {
        cout << "Queue is Full" << endl;
        return;
    }

    q[rear] = a;
    rear = (rear + 1) % size;
    cout << a << " is inserted." << endl;

}
int QueuePrac::delete_q() {
    int tmp;
    if (is_empty()) {
        cout << "Queue is Empty" << endl;
        return 0;
    }

    tmp = q[front];
    front = (front + 1) % size;
    cout << tmp << " deleted " << endl;

    return tmp;
}
bool QueuePrac::is_full() {
    return (rear + 1) % size == front ? true : false;
}
bool QueuePrac::is_empty() {
    return front == rear ? true : false;
}

void QueuePrac::printAll() {
    int i = front;
    if (is_empty()) {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << "Print All numders :" << endl;
    while (i != rear) {
        cout << q[i] << endl;
        i = (i + 1) % size;
    }
}
int main() {

    cout << "Welcome to my Queue!" << endl;
    QueuePrac q(10);
    int input;
    while (true) {
        cout << "1 : push | 2 : pop | 3 : print | ";
        cin >> input;
        if (input == 1) {
            cin >> input;
            q.insert_q(input);
        }
        else if (input == 2) {
            q.delete_q();
        }
        else if (input == 3) {
            q.printAll();
        }
        else break;
    }

    cout << "**Program ended**";

    return 0;
}