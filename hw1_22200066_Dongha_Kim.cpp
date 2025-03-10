#include <iostream>
using namespace std;

void my_sort(int *list, int size){
    int temp;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if (list[i] > list[j]){
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    
}

int main (){
    int list[10] = { 23, 11, 15, 8, 17, 33, 7, 14, 19, 21 };
    int i ;
    my_sort(list, 10); // 배열 list의 원소 10개를 sort하는 함수 for (i = 0; i< 10; i++) cout << list[i] << “\n”;
    for (i = 0; i< 10; i++) cout << list[i] << "\n";
    return 0;
}