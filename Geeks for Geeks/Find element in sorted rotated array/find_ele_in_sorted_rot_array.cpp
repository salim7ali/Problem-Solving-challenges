#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &nums, int L, int R){
    int mid;

    while(L<=R){
        mid = L + floor((R-L)/2);
        if(nums[L]<nums[mid] && nums[mid+1]<nums[R]){
            return mid;
        }else if(nums[L]<nums[mid] && nums[mid+1] > nums[R]){
            L = mid+1;
        }else{  //nums[L]>nums[mid] && nums[mid+1] < nums[R]
            R = mid-1;
        }
    }
    return mid;
}

int main(){
    vector<int> nums = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    
    int pivot = findPivot(nums, 0, nums.size()-1);

    auto itLeft = find(nums.begin(), nums.begin()+pivot, 2);
    auto itRight = find(nums.begin()+pivot+1, nums.end(), 2);

    if(itLeft == nums.begin()+pivot && itRight == nums.end() ){
        cout<<"NOT FOUND";
        // cout<<*itLeft<<" "<<*itRight<<"\n";

    }else if(itLeft != nums.begin()+pivot){
        cout<<"FOUND on index "<<itLeft-nums.begin();
    }else{
        cout<<"FOUND on index "<<itRight - nums.begin();

    }

}