#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool cycleExists(vector<int> &nums){

    int slow = 0;
    int fast = nums[slow]; 
    int count = nums.size();
    while(count--){
        if(slow == fast)
            return true;
        slow = nums[slow];
        fast = nums[fast]; 
        fast = nums[fast]; 
    }
    return false;
}

int main(){
    vector<int> nums = {1, 2,5, 1, 4, 8};

    std::cout<<cycleExists(nums);
}