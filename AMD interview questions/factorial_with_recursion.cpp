// solved using dynamic programming
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int factorialWithRecursion(int n, vector<int> &solved_factorials){
    if(solved_factorials[n] != -1)
        return solved_factorials[n];
    return n*factorialWithRecursion(n-1, solved_factorials);
}

int main(){
    vector<int> solved_factorials(100, -1);
    solved_factorials[0] = 1;   //  0! == 1
    solved_factorials[1] = 1;   //  1! == 1
    
    std::cout<<factorialWithRecursion(0, solved_factorials)<<"\n";
    std::cout<<factorialWithRecursion(1, solved_factorials)<<"\n";
    std::cout<<factorialWithRecursion(3, solved_factorials)<<"\n";
    std::cout<<factorialWithRecursion(5, solved_factorials)<<"\n";
}