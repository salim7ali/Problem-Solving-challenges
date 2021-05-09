#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Prime{
    const int MAX_PRIME =1000;
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
        int left;
        for(left=num-1; left>=2; left--){
            if(isPrime[left])
                break;
        }
        // going right
        int right;
        for(right=num+1; right<MAX_PRIME; right++){
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

    cout<<obj.closestPrime(2)<<"\n";
    cout<<obj.closestPrime(3)<<"\n";
    cout<<obj.closestPrime(4)<<"\n";
    cout<<obj.closestPrime(5)<<"\n";
    cout<<obj.closestPrime(6)<<"\n";
    cout<<obj.closestPrime(7)<<"\n";
    cout<<obj.closestPrime(8)<<"\n";
    cout<<obj.closestPrime(9)<<"\n";
    cout<<obj.closestPrime(10)<<"\n";
}