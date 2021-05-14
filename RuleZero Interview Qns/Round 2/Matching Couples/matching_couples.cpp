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

int factorial(int num){
    int fact=1;
    for(int i=num; i>=1; i--){
        fact *= i;
    }
    return fact;
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
    int arr[] = {10, 5, 4};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout<<MatchingCouples(arr, arr_size)<<"\n";

    int arr1[] = {5, 5, 4};
    int arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    cout<<MatchingCouples(arr1, arr1_size)<<"\n";

    int arr2[] = {2, 2, 2};
    int arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    cout<<MatchingCouples(arr2, arr2_size)<<"\n";
}