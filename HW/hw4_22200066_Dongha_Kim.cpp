#include <iostream>

using namespace std;

class node
{
public:
    string name;
    double num;
    node* left;
    node* right;
    node();
    void set_data(string str, double a);
};

node :: node(){
    left = NULL;
    right = NULL;
}

void node :: set_data(string str, double a){
    name = str;
    num = a;
}

class my_tree
{
public:
    int node_count;
    node* root;

    my_tree();
    int insert_root(node t);
    int insert_left(string tname, node t);
    int insert_right(string tname, node t);


    double score_sum();
    double score_average();
    void print_data_inorder();
    void print_data_preorder();
    void print_data_postorder();
};


double sum_nodes(node* p);
int node_insert_right(node* p, string tname, node t);
int node_insert_left(node* p, string tname, node t);
void printInorder(node* p);
void printPreorder(node* p);
void printPostorder(node* p);

my_tree ::my_tree() {
    node_count = 0;
    root = NULL;
}
int my_tree ::insert_root(node t){
    if (root != NULL) return 0;
    node* p = new node;
    *p = t;
    p->left = NULL;
    p->right = NULL;
    root = p;
    node_count++;
    return 1;
}
int my_tree ::insert_left(string tname, node t){
    int result;
    result = node_insert_left(root, tname, t);
    if (result == 1) node_count++;
    return result;
}
int node_insert_left(node* p, string tname, node t){
    int result = 0;
    if (p == NULL) return 0;
    if(p->name == tname){
        if (p->left != NULL) return -1;
        node* n = new node;
        *n = t;
        n->left = NULL;
        n->right = NULL;
        p->left = n;
        return 1;
    }
    else
    result = node_insert_left(p->left, tname, t);
    if (result != 0) return result;
    else return node_insert_left(p->right, tname, t);
    
}

int my_tree ::insert_right(string tname, node t) {
    int result;
    result = node_insert_right(root,tname,t);
    if (result == 1) node_count++;
    return result;

}

int node_insert_right(node* p, string tname, node t){
    int result;
    if (p == NULL) return 0;
    if(p->name == tname){
        if (p->right != NULL) return -1;
        node* n = new node;
        *n = t;
        n->left = NULL;
        n->right = NULL;
        p->right = n;
        return 1;
    }
    result = node_insert_right(p->left,tname,t);
    if (result != 0) return result;
    return node_insert_right(p->right,tname,t);
}

double my_tree ::score_sum(){
    return sum_nodes(root);
}

double sum_nodes(node* p){
    if(p == NULL) return 0;
    return sum_nodes(p->right) + sum_nodes(p->left) + p->num;
}
double my_tree :: score_average(){
    return score_sum() / (double) node_count;
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
void printPreorder(node* p){
    if (p==NULL) return;
    cout << p->name <<": "<< p->num << endl;
    printPreorder(p->left);
    printPreorder(p->right);
}
void printPostorder(node* p){
    if (p==NULL) return;
    printPostorder(p->left);
    printPostorder(p->right);
    cout << p->name <<": "<< p->num << endl;
}
void my_tree ::print_data_preorder(){
    printPreorder(root);
}
void my_tree ::print_data_postorder(){
    printPostorder(root);
}

int main(){
    my_tree  thetree;

    node  tmp;

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

    cout<< "Score Sum : " << thetree.score_sum() << "\n";

    cout<< "Score Average : " << thetree.score_average() << "\n";

    cout <<"\nInorder Traversal Result \n";

    thetree.print_data_inorder();

    cout << "\nPreorder Traversal Result \n";

    thetree.print_data_preorder();

    cout << "\nPostorder Traversal Result \n";

    thetree.print_data_postorder();

    return 0;
}