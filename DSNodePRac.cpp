#include <string>
#include <iostream>

using namespace std;

class node
{
public:
    string name;
    double score;
    node* link;
    void set_data(string s, double n);
};
void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

//-----------------------------------------------------------------

class my_list
{
    node* head, * tail;

public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();

    double score_sum();
    double get_score(string t_name);
    int count_high_score();
    int remove_a_node(string t_name);
    void insert_a_node(string t_name, node t);
};
my_list::my_list()
{
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t)
{
    node* p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
    if (tail == NULL) tail = p; // 이전 상태가 empty였다면, Tail도 첫node로 tail = p;
}

void my_list::add_to_tail(node t)
{
    node* p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if (tail != NULL)
        tail->link = p; // 이전 상태가 empty가 아니라면
    else
        head = p;      // 이전 상태가 empty였다면 head도 변경 
    tail = p;

}

node my_list::delete_from_head() //삭제한 노드 리턴
{
    node temp;
    node* t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if (head == NULL) // 삭제 후 empty가 되면, tail값도 조정 
        tail = NULL;
    return temp;
}

int my_list::num_nodes()
{
    node* t;
    int count = 0;
    for (t = head; t != NULL; t = t->link) //여기가 어렵네네
        count++;
    return count;
}
bool my_list::list_empty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
double my_list::score_sum() {
    node* t;
    double total = 0;
    for (t = head; t != NULL; t = t->link) //여기가 어려움
        total += t->score;
    return total;
}

double my_list::get_score(string t_name) {
    node* t;
    double score = 0;
    for (t = head; t != NULL; t = t->link)
        if (t->name == "Park") return t->score;
}

int my_list::remove_a_node(string t_name) {
    node* t;
    if (head == tail) return 0;
    for (t = head; t != NULL; t = t->link) {
        if (t->link->name == "Kim") {
            break;
        }
        else if (t->link == NULL) return 0;
    }
    node* temp = t->link;
    t->link = t->link->link;
    delete temp;
    return 1;   
}

double my_list::score_sum() {
    node* t;
    double total = 0;
    for (t = head; t != NULL; t = t->link) //여기가 어려움
        if(t->score >= 80) total++;
    return total;
}

void my_list::insert_a_node(string t_name, node t) {
    node* a;
    if (head == tail) return;
    for (a = head; a != NULL; a = a->link) {
        if (a->link->name == "Kim") {
            break;
        }
        else if (a->link == NULL) return;
    }
    t.link = a->link;
    a->link = a->link->link;
    //delete temp;

}


int main() {
    my_list a;
    node tmp;

    tmp.set_data("Kim", 83.5); //set data >> 노드 하나 안에 데이터 넣기기
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp); // head 위치로 2개의 원소 추가 
    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; // 1단계 점검 

    tmp.set_data("Park", 91.3);
    a.add_to_tail(tmp); // tail 위치로 1개의 원소 추가 
    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; //2단계 점검 

    tmp = a.delete_from_head();
    cout << tmp.name << " is deleted.\n"; // 3단계 점검 

    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);
    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp); // 2개의 원소 추가 
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";
    cout << "Park\'s score : " << a.get_score("Park") << "\n"; // 4단계 점검

    if (a.remove_a_node("Kim") == 1) cout << "Kim is deleted from the list. \n"; // 5단계 점검 

    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; // 최종 점검
    return 0;
}