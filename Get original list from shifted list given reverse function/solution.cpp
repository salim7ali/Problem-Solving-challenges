#include<bits/stdc++.h>
using namespace std;

void reverse(int start, int end, vector<int> &nums){
    for(int i=start; i<= start+floor((end-start)/2); i++){
        swap(nums[i], nums[end-(i-start)]);
    }
}

void getUnshiftedVector(vector<int> nums, int shiftVal){
    
}

int main(){
    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};

    // getUnshiftedVector(nums, 3);
    reverse(3, 8, nums);

    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }

}