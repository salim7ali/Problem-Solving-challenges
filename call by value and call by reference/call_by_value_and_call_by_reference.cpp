#include <bits/stdc++.h>

using namespace std;

void callByValue(int a, int b){
    int temp; 
    temp = a;
    a = b;
    b = temp;
}

void callByReferecne(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    int first = 30, second = 50;

    cout<<"Before first="<<first<<", second="<<second<<"\n";

    callByValue(first, second);
    cout<<"After call by value first="<<first<<", second="<<second<<"\n";
    
    callByReferecne(&first, &second);
    cout<<"After call by reference first="<<first<<", second="<<second<<"\n";

    return 0;
}