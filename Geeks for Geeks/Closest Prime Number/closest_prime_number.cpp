#include<bits/stdc++.h>
using namespace std;


class ClosestPrime{
private:
    int MAX_SIZE = INT_MAX ;
    vector<bool> isPrime = vector<bool>(MAX_SIZE, true);

    void sieveOfEratosthenes(){

        isPrime[0]=false;
        isPrime[1]=false;

        for(int i=2; i<=sqrt(MAX_SIZE); i++){
            if(isPrime[i] == true){
                for(int j=2; (i*j)<=(MAX_SIZE); j++){
                    isPrime[i*j] = false;
                }
            }
            // cout<<i<<" ";
        }
    }

public:
    ClosestPrime(){
        sieveOfEratosthenes();
    }

    int findClosestPrime(int n){

        if(isPrime[n] == true)
            return n;

        int leftIndex, rightIndex;
        for(leftIndex=n-1; isPrime[leftIndex] == false; leftIndex--);
        int leftDist = n-leftIndex-1;
        
        for(rightIndex=n+1; isPrime[rightIndex] == false; rightIndex++);
        int rightDist = rightIndex-n-1;

        if(leftDist == rightDist)
            return leftIndex;
        else if(leftDist < rightDist)
            return leftIndex;
        else //leftDist > rightDist
            return rightIndex;
    }


};

int main(){
    ClosestPrime obj;
    cout<<obj.findClosestPrime(80)<<"\n";
    cout<<obj.findClosestPrime(81)<<"\n";
    cout<<obj.findClosestPrime(82)<<"\n";
    cout<<obj.findClosestPrime(83)<<"\n";
    
}