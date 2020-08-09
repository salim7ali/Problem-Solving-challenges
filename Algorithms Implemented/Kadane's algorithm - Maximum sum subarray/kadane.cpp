// Kadane's algorithm for maximum sum subarray
// Think of subarray as a substring and not subsequence as substrings are to be contiguous wheras subsequences need not be.
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> numbers = {-3, 2, 4, -1, 2, 3, -2};

    int currSum = 0;
    int j=0, k =0;
    int maxSum = INT_MIN;

    for(int i=0; i<numbers.size(); i++){
        currSum += numbers[i];
        
        if(currSum>maxSum){
            maxSum = currSum;
            k = i;
        }
        
        if(currSum<0){
            currSum = 0;
            j = i+1;
        }
    }
    
    cout<<"Original array: ";
    for(int i=0; i<numbers.size(); i++){
        cout<<numbers[i]<<" ";
    }
    cout<<"\nMax sum subarray: ";
    for(int i=j; i<=k; i++){
        cout<<numbers[i]<<" ";
    }
    cout<<"\nMax sum from subarray = "<<maxSum;
    return 0;
}