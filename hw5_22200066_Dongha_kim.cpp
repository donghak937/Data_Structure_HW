#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class node
{
public:
    string name;
    double num;
    node *left;
    node *right;
    node();
    void set_data(string str, double a);
};

node ::node()
{
    left = NULL;
    right = NULL;
}

void node ::set_data(string str, double a)
{
    name = str;
    num = a;
}

class my_tree
{
public:
    int node_count;
    node *root;

    my_tree();
    int insert_root(node t);
    int insert_left(string tname, node t);
    int insert_right(string tname, node t);

    double score_sum();
    double score_average();
    void print_data_inorder();
    void nonrecursive_inorder();
    void print_data_levelorder();
};

double sum_nodes(node *p);
int node_insert_right(node *p, string tname, node t);
int node_insert_left(node *p, string tname, node t);
node* make_copy(node* p);
bool equal_test(node* p1, node* p2);

my_tree ::my_tree()
{
    node_count = 0;
    root = NULL;
}
int my_tree ::insert_root(node t)
{
    if (root != NULL)
        return 0;
    node *p = new node;
    *p = t;
    p->left = NULL;
    p->right = NULL;
    root = p;
    node_count++;
    return 1;
}
int my_tree ::insert_left(string tname, node t)
{
    int result;
    result = node_insert_left(root, tname, t);
    if (result == 1)
        node_count++;
    return result;
}
int node_insert_left(node *p, string tname, node t)
{
    int result = 0;
    if (p == NULL)
        return 0;
    if (p->name == tname)
    {
        if (p->left != NULL)
            return -1;
        node *n = new node;
        *n = t;
        n->left = NULL;
        n->right = NULL;
        p->left = n;
        return 1;
    }
    else
        result = node_insert_left(p->left, tname, t);
    if (result != 0)
        return result;
    else
        return node_insert_left(p->right, tname, t);
}
void printInorder(node* root);
int my_tree ::insert_right(string tname, node t)
{
    int result;
    result = node_insert_right(root, tname, t);
    if (result == 1)
        node_count++;
    return result;
}

int node_insert_right(node *p, string tname, node t)
{
    int result;
    if (p == NULL)
        return 0;
    if (p->name == tname)
    {
        if (p->right != NULL)
            return -1;
        node *n = new node;
        *n = t;
        n->left = NULL;
        n->right = NULL;
        p->right = n;
        return 1;
    }
    result = node_insert_right(p->left, tname, t);
    if (result != 0)
        return result;
    return node_insert_right(p->right, tname, t);
}

double my_tree ::score_sum()
{
    return sum_nodes(root);
}

double sum_nodes(node *p)
{
    if (p == NULL)
        return 0;
    return sum_nodes(p->right) + sum_nodes(p->left) + p->num;
}
double my_tree ::score_average()
{
    return score_sum() / (double)node_count;
}

void my_tree ::print_data_inorder(){
    printInorder(root);
}
void printInorder(node* p){
    if (p==NULL) return;
    printInorder(p->left);
    cout << p->name <<": "<< p->num << endl;
    printInorder(p->right);
}

void copy_tree(my_tree &t1, my_tree t2){
    t1.node_count = t2.node_count;
    t1.root = make_copy(t2.root);
}

node* make_copy(node* p){
    node* t;
    if(p == NULL) return NULL;
    t = new node;
    *t = *p;
    t->left = make_copy(p->left);
    t->right = make_copy(p->right);
    return t;
}

void my_tree ::nonrecursive_inorder(){
    node* p = root;
    stack<node*> s;
    while (true)
    {
        while(p != NULL){
            s.push(p);
            p = p->left;
        }
        if (s.size() == 0) return;
        p = s.top();
        cout << p->name << " : " <<p->num << endl;
        s.pop();
        p = p->right;
    }
}
void my_tree ::print_data_levelorder(){
    queue<node*> q;
    node* t;
    if (root == NULL) return;

    q.push(root);
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        cout << t->name << " : " << t->num << endl;
        if (t->left != NULL) q.push(t->left);
        if (t->right != NULL) q.push(t->right);
    }
    
}

bool equal_tree(my_tree t1, my_tree t2){
    if(t1.node_count != t2.node_count) return false;
    return equal_test(t1.root, t2.root);
}

bool equal_test(node* p1, node* p2){
    return ((p1 == NULL) && (p2 == NULL) || (p1 != NULL) && (p2 != NULL) && (p1->name == p2->name) && (p1->num == p2->num) && equal_test(p1->left, p2->left) && equal_test(p1->right, p2->right));

}

int main()
{
    my_tree thetree;

    node tmp;

    tmp.set_data("Kim", 8.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 6.5);
    thetree.insert_left("Kim", tmp);
    tmp.set_data("Park", 8.3);
    thetree.insert_right("Kim", tmp);
    tmp.set_data("Choi", 7.2);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 9.0);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 7.7);
    thetree.insert_right("Park", tmp);
    cout << "\nNon-recursive Inorder Result \n";
    thetree.nonrecursive_inorder();
    cout << "\nLevel-Order traversal Result \n";
    thetree.print_data_levelorder();
    my_tree tree2;
    copy_tree(tree2, thetree);
    cout << "\nThe inorder traversal Result of the new tree \n";
    tree2.print_data_inorder();
    if (equal_tree(tree2, thetree))
        cout << "Yes\n";
    else
        cout << "No\n";
    tmp.set_data("Youn", 7.7);
    thetree.insert_right("Cho", tmp);
    if (equal_tree(tree2, thetree))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}