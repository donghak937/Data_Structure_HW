#include <iostream>
#include <string>
using namespace std;

class node
{
public:
        string name;
        double score;
        node *link;
        void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
        name = s;
        score = n;
}

class my_list
{
        node *head;

public:
        my_list()
        {
                head = NULL;
        }
        void add_to_head(node t);
        double min_max_range();
        int modify_score(string tname, double tscore);
        void show_all_data();
};

void my_list::add_to_head(node t)
{
        node *p;
        p = new node;
        (*p) = t;
        p->link = head;
        head = p;
}

void my_list::show_all_data()
{
        node *p;

        for (p = head; p != NULL; p = p->link)
                cout << p->name << " : " << p->score << endl;
}
int my_list::modify_score(string tname, double tscore)
{
        node *p;

        for (p = head; p != NULL; p = p->link){
                if (p->name == tname){
                        p->score = tscore;
                        return 1;
                }
        }
        return 0;
}

double my_list::min_max_range()
{
        node *p;
        double max = 0;
        double min = 101;
        for (p = head; p != NULL; p = p->link){
                if (p->score > max){
                        max = p->score;
                }
                else if (p->score < min){
                        min = p->score;
                }
        }
        return max - min;
}

int main()
{
        my_list a;
        node tmp;
        tmp.set_data("Kim", 83.5);
        a.add_to_head(tmp);
        tmp.set_data("Lee", 58.2);
        a.add_to_head(tmp);
        tmp.set_data("Park", 91.3);
        a.add_to_head(tmp);
        tmp.set_data("Choi", 55.1);
        a.add_to_head(tmp);
        tmp.set_data("Ryu", 77.1);
        a.add_to_head(tmp);
        tmp.set_data("Yang", 47.9);
        a.add_to_head(tmp);
        tmp.set_data("Hong", 78.2);
        a.add_to_head(tmp);

        cout << "\nThe list before the processing. \n";
        a.show_all_data();

        if (a.modify_score("Choi", 75.6) == 1)

                cout << "Choi's score has been changed. \n";
        else
                cout << "Modification FAILED !! \n";

        cout << "After the modification \n";

        a.show_all_data();

        cout << "The deviation between Max. and Min. value = " << a.min_max_range() << endl
             << endl;

        return 0;
}
