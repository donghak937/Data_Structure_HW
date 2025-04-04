#include <iostream>
//#define SIZE 10;
using namespace std;

void my_sort(int *list, int start, int end){
    if (start >= end){
        return;
    }

    int temp;
    int pivot = start;
    int i = pivot + 1;
    int j = end;

    while(j >= i){
        while(i <= end && list[i] > list[pivot]){
            i++;
        }
        while(j > start && list[j] < list[pivot]){
            j--;
        }
        if(i > j){
            temp = list[pivot];
            list[pivot] = list[j];
            list[j] = temp;
        }
        else {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    
    my_sort(list, start, j-1);
    my_sort(list, j+1, end);
}

int main (){
    int list[10] = { 23, 11, 15, 8, 17, 33, 7, 14, 19, 21 };
    int i ;
    my_sort(list, 0, 9); // 배열 list의 원소 10개를 sort하는 함수 for (i = 0; i< 10; i++) cout << list[i] << “\n”;
    for (i = 0; i< 10; i++) cout << list[i] << "\n";
    return 0;
}