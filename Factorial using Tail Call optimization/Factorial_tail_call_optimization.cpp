// #include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Factorial{
public:
    int factOfNumber(int);
    int factOfNumTailCallOptimized(int, int);
};

int Factorial::factOfNumber(int number){
    if(number == 0)
        return 1;

    return number*factOfNumber(number-1);
}

int Factorial::factOfNumTailCallOptimized(int number, int accumulator){
    if(number == 0)
        return accumulator;

    return factOfNumTailCallOptimized(number-1, (accumulator*number));
}


int main(){
    Factorial obj;
    int number = 4;
    cout<<"Normal Factorial function: "<<obj.factOfNumber(number)<<"\n";

    cout<<"Tail Call Optimized Factorial function: "<<obj.factOfNumTailCallOptimized(number, 1);
}