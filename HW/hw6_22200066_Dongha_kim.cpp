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
    int n_d2_nodes();
    int n_d1_nodes();
    int n_leaf_nodes();
};

double sum_nodes(node *p);
int node_insert_right(node *p, string tname, node t);
int node_insert_left(node *p, string tname, node t);
int node2_count(node* p);
int node1_count(node* p);
int node0_count(node* p);


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
int my_tree :: n_d2_nodes(){
    node* p = root;
    
    if (p == NULL) return 0;
    int n = 0;
    n += node2_count(p);

    return n;
}
int node2_count(node* p){
    if (p == NULL) return 0;

    if (p->left != NULL && p->right != NULL)
        return 1 + node2_count(p->left) + node2_count(p->right);
        
    return node2_count(p->left) + node2_count(p->right);
}

int my_tree :: n_d1_nodes(){
    node* p = root;
    
    if (p == NULL) return 0;
    int n = 0;
    n += node1_count(p);

    return n;
}
int node1_count(node* p){
    if (p == NULL) return 0;

    if (p->left == NULL && p->right != NULL)
        return 1 + node1_count(p->left) + node1_count(p->right);

    if (p->left != NULL && p->right == NULL)
        return 1 + node1_count(p->left) + node1_count(p->right);

    if (p->left != NULL && p->right != NULL)
        return node1_count(p->left) + node1_count(p->right);

    return 0;
}

int my_tree :: n_leaf_nodes(){
    node* p = root;
    
    if (p == NULL) return 0;
    int n = 0;
    n += node0_count(p);

    return n;
}
int node0_count(node* p){
    if (p == NULL) return 0;

    if (p->left == NULL && p->right == NULL)
        return 1;

    return node0_count(p->left) + node0_count(p->right);

}
int main()
{
    my_tree thetree;
    node tmp;
    tmp.set_data("Kim", 81.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 86.2);
    thetree.insert_left("Kim", tmp);
    tmp.set_data("Park", 79.4);
    thetree.insert_right("Kim", tmp);
    tmp.set_data("Choi", 77.8);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 92.2);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 68.6);
    thetree.insert_right("Park", tmp);
    tmp.set_data("Yang", 72.8);
    thetree.insert_left("Ryu", tmp);
    tmp.set_data("Jung", 62.3);
    thetree.insert_left("Cho", tmp);

    cout << "The number of degree-2 nodes : " << thetree.n_d2_nodes() << endl; // degree 2인 node 수
    cout << "The number of degree-1 nodes : " << thetree.n_d1_nodes() << endl; // degree 1인 node 수
    cout << "The number of leaf nodes : " << thetree.n_leaf_nodes() << endl;   // leaf node 수

    return 0;
}