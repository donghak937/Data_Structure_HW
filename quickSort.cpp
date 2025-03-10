#include <iostream>
using namespace std;

void my_sort(int *list, int end, int start){
    int temp;
    int pivot = start;
    int i;
    int j;
}

int main (){
    int list[10] = { 23, 11, 15, 8, 17, 33, 7, 14, 19, 21 };
    int i ;
    my_sort(list, 10 - 1, 0); // 배열 list의 원소 10개를 sort하는 함수 for (i = 0; i< 10; i++) cout << list[i] << “\n”;
    for (i = 0; i< 10; i++) cout << list[i] << "\n";
    return 0;
}