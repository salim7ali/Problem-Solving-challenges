#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Prime{
    const MAX_PRIME =1000;
    vector<bool> primeNos = vector<bool> (MAX_PRIME, true);
public:
    Prime(){
        primeNos[0] = false;
        primeNos[1] = false;
        sieveOfEratosthenes();
    }

    void sieveOfEratosthenes(){
        for(int i=2; i<sqrt(MAX_PRIME-1); i++){
            for(int j=2; i*j<=MAX_PRIME; j++){
                primeNos[i*j] = false;
            }
        }    
    }

    int closestPrime(int num){

    }
};

int main(){
    Prime obj;
}