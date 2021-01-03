// https://www.youtube.com/watch?v=VzQ2KacyDLw&t=46s

#include<bits/stdc++.h>
using namespace std;

void showVector(vector<int> &nums){
    for(int num: nums)
        cout<<num<<" ";
    cout<<"\n";
}

void setZeros(vector<int> &nums){
    int j=-1;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] != 0){
            j += 1;
            nums[j] = nums[i];
        }
    }
    for(j=j+1; j<nums.size(); j++)
        nums[j] = 0;
}

int main(){
    vector<int> nums = {2, 3, 0, 1, 0, 3, 1};

    showVector(nums);
    setZeros(nums);
    showVector(nums);
}