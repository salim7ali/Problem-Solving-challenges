// sort array with only iterate and prefix reverse operations
// https://www.youtube.com/watch?v=V5yZ14wX4B8&t=63s
#include<bits/stdc++.h>
using namespace std;

void prefReverse(vector<int> &arr, int end){
    end +=1;
    for(int i=0; i<(end/2); i++)
        swap(arr[i], arr[end-i-1]);
}

void showArr(vector<int> &arr){
    for(int num: arr)
        cout<<num<<" ";
    cout<<"\n";
}

void restrictedSort(vector<int> &arr){
    int j;
    for(int i=1; i<arr.size(); i++){
        j=0;
        while(arr[j]<arr[i])
            j++;
        prefReverse(arr, j-1);
        prefReverse(arr, i-1);
        prefReverse(arr, i);
        prefReverse(arr, j);
    }
}

int main(){
    vector<int> arr = {5, 3, 1, 4, 2};
    showArr(arr);
    restrictedSort(arr);    
    showArr(arr);
}