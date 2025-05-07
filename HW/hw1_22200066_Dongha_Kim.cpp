// 22200066 김동하 데이터구조 01분반 1번 과제

#include <iostream>
using namespace std;

class weight{
    int gram = 0;
    int kg = 0;
    public:
    void set_weight(int n1, int n2);
    int get_weight();
    bool is_heavy();
    void add_grams(int a);
};

void weight::set_weight(int n1, int n2){ //값 집어 넣기기
    kg = n1;
    gram = n2;
}

int weight::get_weight(){ //그램수 리턴턴
    return kg * 1000 + gram;
}
bool weight::is_heavy(){ //무거운지 판단단
    if( kg >= 10) return true;
    else return false;
}
void weight::add_grams(int a){
    gram += a;
    if (gram >= 1000){
        kg += gram / 1000;
        gram %= 1000; 
    }
}

weight add_weight(weight w1, weight w2){
    weight temp;
    temp.set_weight((w1.get_weight() + w2.get_weight()) / 1000, (w1.get_weight() + w2.get_weight()) % 1000);
    return temp;
}

int main( ) { 
    weight w1, w2, w3; // weight라는 class object 3개 생성
    w1.set_weight(12, 800); // w1을 3kg 400 g으로
    if (w1.is_heavy()) cout << "Heavy.\n";
    else cout << "Light";

    w2.set_weight(2, 900); // w2을 2kg 700 g으로
    w2.add_grams(500);      //w2을 3kg 400 g으로
    w3 = add_weight(w1, w2); // w1과 w2을 더하여 w3에  w3는 16kg 200g
    cout << w3.get_weight( ) << " grams\n"; // w3의 값 ‘16200 grams’ 출력

}
