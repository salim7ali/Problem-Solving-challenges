#include<bits/stdc++.h>
using namespace std;

int memFibonacci(int n, int memo[]){
    if(memo[n] == NULL){
        if(n==1 ||n==2)
            memo[n]= 1;
            return 1;
        memo[n]= memFibonacci(n-1, memo) + memFibonacci(n-2, memo);
        return memo[n];
    }
    else
        return memo[n];
}

int main(){
    int n = 6;//6th fibonacci number
    int memo[7];
    memo[0] = 0;
    cout<<memFibonacci(n, memo);
}