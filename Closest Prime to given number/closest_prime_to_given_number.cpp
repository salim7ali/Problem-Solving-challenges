#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Prime{
    const MAX_PRIME =1000;
    vector<bool> isPrime = vector<bool> (MAX_PRIME, true);
public:
    Prime(){
        isPrime[0] = false;
        isPrime[1] = false;
        sieveOfEratosthenes();
    }

    void sieveOfEratosthenes(){
        for(int i=2; i<sqrt(MAX_PRIME-1); i++){
            for(int j=2; i*j<=MAX_PRIME; j++){
                isPrime[i*j] = false;
            }
        }    
    }

    int closestPrime(int num){
        if(isPrime[num])
            return num;
        
        // going left
        for(int left=num-1; left>=2; left--){
            if(isPrime[left])
                break;
        }
        // going right
        for(int right=num+1; right<MAX_PRIME; right++){
            if(isPrime[right])
                break;
        }

        // find whether left or right prime is closer
        int left_dist = num-left;
        int right_dist = right-num;
        if(left_dist>right_dist)
            return right;
        else //left_dist<=right_dist
            return left;
    }
};

int main(){
    Prime obj;
}