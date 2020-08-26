// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void allPrimesTillNumber(int number){
    vector<bool> isPrime(number+1, true); 
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i=2; i<=sqrt(number); i++){
        if(isPrime[i] == true){
            for(int j=2; (i*j)<=number; j++){
                isPrime[i*j] = false;
            }
        }
    }

    for(int i=0; i<isPrime.size(); i++){
        if(isPrime[i] == true)
            cout<<i<<" ";
    }
}

int main(){
    int number = 30;

    allPrimesTillNumber(number);
}