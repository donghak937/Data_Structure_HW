#include <iostream>
using namespace std;
#define MAX 20

class element{
public:
    int num;
    void set_data(int a);    
};

void element::set_data(int a){
    num = a;
}

class My_heap {
private:
    int csize;
    element h[MAX];
    void adjust(int a);
public:
    My_heap();
    My_heap(element a[], int size);
    int h_size();
    void insert_heap(element a);
    element delete_heap();
    bool is_full();
    bool is_empty();
};

My_heap::My_heap(){
    csize = 0;
}

My_heap::My_heap(element a[], int size){
    for(int i = 1; i <= size; i++){
        h[i] = a[i-1];
    }
    for(int i = size / 2; i >= 1; i--){
        adjust(i);
    }
}

int My_heap::h_size(){
    return csize;
}
void My_heap::insert_heap(element a){
    int k;
    csize++;
    
    k = csize;
    while ((k != 1) && (h[k/2].num < a.num) ) {
        h[k] = h[k/2];
        k /= 2;
    }
    h[k] = a;
}
element My_heap::delete_heap(){
    element t = h[1];
    element tmp = h[csize];
    int c = 2;
    int p = 1;
    csize--;
    while(c <= csize){
        if((c < csize) && (h[c].num < h[c+1].num)){
            c++;
        }
        if (h[p].num < h[c].num){
            h[p] = h[c];
            p = c;
            c *= 2;
        }
        else break;
    }
    h[p] = tmp;
    return t;
}
bool My_heap::is_full(){
    return csize >= MAX;
}
bool My_heap:: is_empty(){
    return csize == 0;
}
void My_heap::adjust(int a){
    element t = h[a];
    int tmpkey = h[a].num;
    int c = a * 2;
    while (c <= csize){
        if ( (c < csize) && (tmpkey < h[c+1].num)){
            c++;
        }
        if (tmpkey > h[c].num){
            break;
        }
        else{
            h[c / 2] = h[c];
            c *= 2;
        }
    }
    h[c/2] = t;
}

int main() {
    My_heap h;
    h.insert_heap();
    return 0;
}