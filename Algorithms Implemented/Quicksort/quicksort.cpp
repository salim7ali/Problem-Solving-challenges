#include <bits/stdc++.h>

using namespace std;

int partition(int* arr, int start, int stop){
    int i=start-1;

    for(int j=start; j<stop; j++){
        if(arr[j]<arr[stop]){
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[stop]);
    return i+1;
}

void quickSort(int* arr, int start, int stop){
    int partIndex;
    if(start<stop){
        partIndex = partition(arr, start, stop);
        quickSort(arr, start, partIndex-1);
        quickSort(arr, partIndex+1, stop);
    }
}

void outputArr(int* nums, int numsSize){
    for(int i=0; i<numsSize; i++){
        cout<<nums[i]<<" ";
    }
}
int main(){
    int nums[] = {8, 34, 2, 43, 32, 634, 1, 23, 94, 23, 2, 9};
    int numsSize = *(&nums + 1) - nums;
    
    cout<<"Before:\n";
    outputArr(nums, numsSize);
    quickSort(nums, 0, numsSize);
    cout<<"\nAfter:\n";
    outputArr(nums, numsSize);

}
