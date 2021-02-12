#include<bits/stdc++.h>
using namespace std;

int minRopeConnectCost(vector<int> &nums){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(auto ele: nums)
        minHeap.push(ele);

    int resultCost = 0;

    while(minHeap.size() >1){
        int minEle = minHeap.top(); 
        minHeap.pop();
        int secMinEle = minHeap.top(); 
        minHeap.pop();

        int currCost = minEle + secMinEle;
        resultCost += currCost;
        minHeap.push(currCost);
    }
    return resultCost;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    cout<<minRopeConnectCost(nums);
}