// solved using dynamic programming
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;



class Factorial{

    vector<int> solved_factorials=vector<int> (100, -1);
public:

    Factorial(){
        solved_factorials[0] = 1;   //  0! == 1
        solved_factorials[1] = 1;   //  1! == 1
    }

    int factorialWithRecursion(int n){
        if(solved_factorials[n] != -1)
            return solved_factorials[n];
        return n*factorialWithRecursion(n-1);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    Factorial obj;
    
    std::cout<<obj.factorialWithRecursion(0)<<"\n";
    std::cout<<obj.factorialWithRecursion(1)<<"\n";
    std::cout<<obj.factorialWithRecursion(3)<<"\n";
    std::cout<<obj.factorialWithRecursion(5)<<"\n";
}