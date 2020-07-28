// Solved the problem for two different time complexities
// https://www.geeksforgeeks.org/check-if-two-arrays-are-equal-or-not/


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Time complexity = O(n^2)
string bruteForce(vector<int> arr1, vector<int> arr2){
    int i=-1;
    int temp;
    
    for(int k=0; k<arr2.size(); k++){
        for(int j=i+1; j<arr1.size(); j++){
            if(arr2[k] == arr1[j]){
                i +=1;
                temp = arr1[j];
                arr1[j] = arr1[i];
                arr1[i] = temp;
                k += 1;
            }
        }
    }

    if(i == arr1.size()-1)
        return "Same";
    else
        return "Not Same";
}

// Time complexity = O(nlogn)
string usingSort(vector<int> arr1, vector<int> arr2){
    sort(arr1.begin(), arr1.end()); //merge sort solves in nlogn
    sort(arr2.begin(), arr2.end());

    if(arr1.size() == arr2.size()){
        for(unsigned int i=0; i<arr1.size(); i++){
            if(arr1[i] != arr2[i])
                return "Not Same";
        }
        return "Same";
    }
    else
        return "Not Same";
}

int main(){
    vector<int> arr1= {1, 2, 5, 4, 0};
    vector<int> arr2= {2, 4, 5, 0, 1};

    cout<<"Using brute force(slow): "<<bruteForce(arr1, arr2)<<"\n";

    cout<<"Using sort(fast): "<<usingSort(arr1, arr2)<<"\n";
}