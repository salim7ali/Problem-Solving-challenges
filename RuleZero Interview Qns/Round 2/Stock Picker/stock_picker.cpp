#include<bits/stdc++.h>
using namespace std;

int StockPicker(int arr[], int arrLength){
    vector<vector<int, int>> incSequences;
    
    int low=-1;
    int high=-1;
    
    int i=0;
    while(i<arrLength-1){
        // start edge case valley
        if(i==0 && arr[i+1]>arr[i]){
            low=0;
            while(arr[i]<arr[i+1]){
                high = i;
                i++;
            }
            incSequences.push_back({low, high});
        }
        // other valleys
        if(i!= 0 && arr[i-1]>=arr[i] && arr[i]<arr[i+1]){
            low = i;
            while(arr[i]<arr[i+1]){
                i++;
                high = i;
            }
            incSequences.push_back({low, high});
        }
        i++;
    }
}

int main(){
    int stocks[] = {44, 30, 24, 32, 35, 30, 40, 38, 15};
    int stocks_size = sizeof(stocks)/sizeof(stocks[0]);
    StockPicker(stocks, stocks_size);
}