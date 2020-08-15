// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void countSwaps(vector<int> a) {
    int count = 0;
    for(int j=a.size()-1; j>0; j--){
        for(int i=1; i<=j; i++){
            if(a[i-1]>a[i]){
                swap(a[i-1],a[i]);
                count += 1;    
            }
        }
    }

    cout<<"Array is sorted in "<<count<<" swaps.\n";
    cout<<"First Element: "<<a[0]<<"\n";
    cout<<"Last Element: "<<a[a.size()-1]<<"\n";
}

int main(){
    vector<int> nums = {6, 4, 1};   
    countSwaps(nums);
}
