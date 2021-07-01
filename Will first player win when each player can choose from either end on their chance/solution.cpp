// https://www.youtube.com/watch?v=Afnthubp_-M&t=1255s
#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> matrix){
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix.size(); j++){
            cout<<matrix[i][j]<<" ";
        }cout<<"\n";
    }
}

bool willFirstPlayerWin(vector<int> nums){
    vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), 0));

    int j=0;
    for(int outer_i=0; outer_i<dp.size(); outer_i++){
        for(int i=0; i<dp.size()-outer_i; i++){
            j = i+outer_i;

            if(i==j){
                dp[i][i] = nums[i];
                continue;
            }
            if(abs(j-i)==1){
                dp[i][j] = max(nums[i], nums[j]);
                continue;
            }
            dp[i][j] = max(nums[i]+min(dp[i+2][j], dp[i+1][j-1]), nums[j]+min(dp[i][j-2], dp[i+1][j-1]));
        }
    }
    display(dp);
    return true;
}

int main(){
    cout<<willFirstPlayerWin({3, 2, 5, 5})<<"\n";
    cout<<willFirstPlayerWin({20, 30, 2, 10})<<"\n";
}