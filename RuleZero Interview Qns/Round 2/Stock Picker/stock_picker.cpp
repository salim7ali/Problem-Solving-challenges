#include<bits/stdc++.h>
using namespace std;

int StockPicker(int arr[], int arrLength){
    vector<vector<int>> incSequences;
    
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
            incSequences.push_back({arr[low], arr[high]});
        }
        // other valleys
        if(i!= 0 && arr[i-1]>=arr[i] && arr[i]<arr[i+1]){
            low = i;
            while(arr[i]<arr[i+1]){
                i++;
                high = i;
            }
            incSequences.push_back({arr[low], arr[high]});
        }
        i++;
    }

    // merging overlapping ranges
    for(int i=0; (i<incSequences.size()-1) && (incSequences[i][0] != INT_MIN && incSequences[i][1]!=INT_MIN); i++){
        if(incSequences[i][1]>=incSequences[i+1][0]){
            // merged range
            incSequences[i+1][0] = incSequences[i][0];

            // discarding dropped range
            incSequences[i][0] = INT_MIN;
            incSequences[i][1] = INT_MIN;
        }
    }

    int maxProfit =0;
    for(int i=0; i<incSequences.size(); i++){
        // if valid
        if(incSequences[i][0] != INT_MIN && incSequences[i][1] != INT_MIN){
            maxProfit = max(maxProfit, incSequences[i][1]-incSequences[i][0]);
        }
    }
    if(maxProfit==0)
        return -1;
    else
        return maxProfit;
}

int main(){
    int stocks[] = {44, 30, 24, 32, 35, 30, 40, 38, 15};
    int stocks_size = sizeof(stocks)/sizeof(stocks[0]);
    cout<<StockPicker(stocks, stocks_size);
}