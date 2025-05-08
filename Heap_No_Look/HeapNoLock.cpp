#include <iostream>
#define MAX 100

using namespace std;

class element{
private:
    double score;
    string name;
public:
    double getScore();
    string getName();
    void set_data(double score, string name);
};

string element :: getName(){
    return name;
}

double element :: getScore(){
    return score;
}

void element :: set_data(double score, string name){
    this->score = score;
    this->name = name;
}

class heap{
private:
    element h[MAX];
    int csize;
    void adjust(int root);
public:
    heap();
    heap(element a[], int size);
    int h_size();
    void insert_heap(element t);
    element delete_heap();
    bool is_full();
    bool is_empty();
};

void heap :: adjust(int root){
    element a = h[root];
    int c = root * 2;

    while(c <= csize){
        if((c < csize) && (h[c].getScore() < h[c+1].getScore())){
            c++;
        }
        if (h[c].getScore() > h[root].getScore()){
            h[root] = h[c];
            root = c;
            c *= 2;
        }
        else break;
    }

    h[root] = a;
}

heap :: heap(){
    csize = 0;
}
heap :: heap(element a[], int size){
    for(int i = 1; i < size; i++)
        h[i] = a[i-1];
    for(int i = size / 2; i >= 1; i--)
        adjust(i);
}
int heap :: h_size(){
    return csize;
}
void heap :: insert_heap(element t){
    csize++;
    int a = csize;

    while((a != 1) && h[a / 2].getScore() < t.getScore()){
        if ( h[a / 2].getScore() < t.getScore()){
            h[a] = h[a / 2];
            a /= 2;
        }
    }
    h[a] = t;
}
element heap :: delete_heap(){
    element t = h[1];
    element tmp = h[csize];
    csize--;
    int c = 2;
    int p = 1;

    while(c <= csize){
        if((c < csize) && (h[c].getScore() < h[c+1].getScore())){
            c++;
        }
        if(h[p].getScore() < h[c].getScore()){
            h[p] = h[c];
            p = c;
            c *= 2;
        }
        else{
            break;
        }
    }
    h[p] = tmp;
    return t;

}
bool heap :: is_full(){
    return csize >= MAX;
}
bool heap :: is_empty(){
    return csize == 0;
}

int main(){

}