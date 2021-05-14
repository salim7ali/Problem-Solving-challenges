#include<bits/stdc++.h>
using namespace std;

unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int MatchingCouples(int arr[], int arrLength){
    int const BOYS = arr[0];
    int const GIRLS = arr[1];
    int const PAIRING = arr[2];

    int half = PAIRING/2;
    
    int result = nChoosek(BOYS, half) * nChoosek(GIRLS, half);
    result *= factorial(half);
    
    return result;
}

int main(){
    
}