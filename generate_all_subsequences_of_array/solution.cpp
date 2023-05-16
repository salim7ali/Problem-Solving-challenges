#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> currSubequnce){
    for(int i=0; i<currSubequnce.size(); i++){
        cout<<currSubequnce[i]<<" ";
    }cout<<"\n";
}

void generateAllSubsequences(vector<int> &nums, int currIndex, vector<int> currSubequnce){
    if(currIndex==nums.size()){
        printVector(currSubequnce);
        return;
    }
    vector<int> pickedSubsequence = currSubequnce;
    pickedSubsequence.push_back(nums[currIndex]);
    generateAllSubsequences(nums, currIndex+1, pickedSubsequence);   // pick
    generateAllSubsequences(nums, currIndex+1, currSubequnce);   // dont pick
}

int main(){
    vector<int> nums = {1, 7, 11};

    generateAllSubsequences(nums, 0, {});
}