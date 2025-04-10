#include <iostream>
#include <string>

//  An ordered list using linked list
//  Practice in class

using namespace std;

class node {
public:
        string   name;
        double      score;
        node *link;
        void   set_data(string   s, double n);
};

void   node::set_data(string s, double n) {
           name = s;
           score = n;
}

class my_list {
        node   *head;
public:
        my_list() {
        head = NULL;
        }
        void ordered_list_insert(node   t);
        void show_all_data();
        void insert_a_node(string tname, node t);
        void add_to_head(node t);
};

void my_list::ordered_list_insert(node t)
{
        string b;
        if(head == NULL){
                node   *p;
                p = new   node;
                (*p) = t;
                p->link = head;
                head = p;
                return;
        }
        else {
                node* a;
                if (head == NULL) return;
                for (a = head; a != NULL; a = a->link) {
                    if (a->name <= t.name) {
                        b = a->name;
                    }

                }   
        }
        insert_a_node(b,t);
}

void my_list::show_all_data()
{
        node *p;

        for ( p = head; p != NULL; p = p->link)
                cout << p->name << " : " << p->score << endl;

}

void my_list::insert_a_node(string tname, node t)
{
    node* a;

    if (head == NULL) return;
    for (a = head; a != NULL; a = a->link) {
        if (a->name == tname) {
            break;
        }
        else if (a->link == NULL){
            node* temp = new node;
            *temp = t;
             temp->link = head;
             head = temp;
             return;

        }
    }

    node* temp = new node;
    *temp = t;

    temp->link = a->link;
    a->link = temp;
    return;
}

int main()
{
my_list    thelist;
node   tmp;
        tmp.set_data("Kim", 73.5);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Lee", 82.2);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Park", 51.3);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Choi", 95.1);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Ryu", 71.3);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Yang", 58.2);
        thelist.ordered_list_insert(tmp);
        tmp.set_data("Hong", 83.5);
        thelist.ordered_list_insert(tmp);

        cout << "\nThe list after insertions\n";
        thelist.show_all_data();
        cout << endl;

        return 0;
}



