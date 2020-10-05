#include<iostream>

#define test(x) x+x
using namespace std;

int main(){
    int total = test(3) * test(4); // 3 + 3 * 4 + 4
    cout<<total;
}