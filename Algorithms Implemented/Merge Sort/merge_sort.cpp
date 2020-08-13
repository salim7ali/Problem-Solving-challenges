// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

void merge(int* nums, int start, int pivot, int end){
    int i=0, j=0, k=start-1;

    vector<int> leftSorted;
    leftSorted.assign(nums+start, nums+pivot+1);
    leftSorted.push_back(INT_MAX);

    vector<int> rightSorted;
    rightSorted.assign(nums+pivot+1, nums+end+1);
    rightSorted.push_back(INT_MAX);

    while(k != end){
        k += 1;
        if(leftSorted[i]>=rightSorted[j]){
            nums[k] = rightSorted[j];
            j += 1;
        }else{
            nums[k] = leftSorted[i];
            i += 1;
        }
    }
}

void mergeSort(int* nums, int start, int end){
    int pivot;
    if(start<end){
        pivot = start + (floor(end-start)/2);
        mergeSort(nums, start, pivot);
        mergeSort(nums, pivot+1, end);
        merge(nums, start, pivot, end);
    }
}

void displayArray(int* nums, int numsSize){
    for(int i=0; i<numsSize; i++){
        cout<<nums[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int nums[] = {8, 34, 2, 43, 32, 634, 1, 23, 94, 23, 2, 9};
    int numsSize = *(&nums+1)-nums;

    cout<<"Before sort:\n";
    displayArray(nums, numsSize);
    mergeSort(nums, 0, numsSize-1);
    cout<<"After Merge sort:\n";
    displayArray(nums, numsSize);
}


