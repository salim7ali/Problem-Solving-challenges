#include <bits/stdc++.h>
using namespace std;

void insertionSort(int* nums, int size){
    int temp;
    for(int j=1; j<size; j++){
        temp = nums[j];
        for(int i=j-1; i>=-1; i--){
            if(nums[i]>temp){
                nums[i+1] = nums[i];
            }else{
                nums[i+1] =temp;
                break;
            }
        }
    }
}

int main(){
    int nums[] = {8, 34, 2, 43, 32, 634, 1, 23, 94, 23, 2, 9};
    int numsSize = *(&nums+1) - nums;
    
    insertionSort(nums, numsSize);
    for(int i=0; i<numsSize; i++)
        cout<<nums[i]<<" ";
    
}