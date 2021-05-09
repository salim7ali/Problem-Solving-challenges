// solved using dynamic programming
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;



class Factorial{

public:
    int factorialWithRecursion(int n, vector<int> &solved_factorials){
        if(solved_factorials[n] != -1)
            return solved_factorials[n];
        return n*factorialWithRecursion(n-1, solved_factorials);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> solved_factorials(100, -1);
    solved_factorials[0] = 1;   //  0! == 1
    solved_factorials[1] = 1;   //  1! == 1

    Factorial obj;
    
    std::cout<<obj.factorialWithRecursion(0, solved_factorials)<<"\n";
    std::cout<<obj.factorialWithRecursion(1, solved_factorials)<<"\n";
    std::cout<<obj.factorialWithRecursion(3, solved_factorials)<<"\n";
    std::cout<<obj.factorialWithRecursion(5, solved_factorials)<<"\n";
}