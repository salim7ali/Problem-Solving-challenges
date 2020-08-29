// #include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<ctime>
#include<math.h>

using namespace std;

void merge(int* nums, int L, int pivot, int R){
    int i=0, j=0, k=L-1;
    vector<int> leftSorted;
    vector<int> rightSorted;

    leftSorted.assign(nums+L, nums+pivot+1); 
    leftSorted.push_back(INT_MAX);
    
    rightSorted.assign(nums+pivot+1, nums+R+1);
    rightSorted.push_back(INT_MAX);

    while(k<R){
        k += 1;
        if(leftSorted[i]<rightSorted[j]){
            nums[k] = leftSorted[i];
            i += 1;
        }else{
            nums[k] = rightSorted[j];
            j += 1;
        }
    } 
}

void mergeSort(int* nums, int L, int R){
    int pivot;
    if(L<R){
        pivot = L + floor((R-L)/2);
        mergeSort(nums, L, pivot);
        mergeSort(nums, pivot+1, R);
        merge(nums, L, pivot, R);
    }
}

void dispArray(int* arr, int SIZE){
    for(int i=0; i<SIZE; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int numbers[10];
    const int SIZE = *(&numbers+1)-numbers;

    //generating array of random numbers
    srand(time(0));
    for(int i=0; i<SIZE; i++)
        numbers[i] = (rand()%100)+1;

    cout<<"Before mergesort:\n";
    dispArray(numbers, SIZE);
    
    mergeSort(numbers, 0, SIZE-1);

    cout<<"After mergesort:\n";
    dispArray(numbers, SIZE);
    
}
