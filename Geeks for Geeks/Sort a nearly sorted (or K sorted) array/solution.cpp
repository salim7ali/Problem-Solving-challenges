// https://www.youtube.com/watch?v=tJK7vjNKdLY&t=24s
// https://www.geeksforgeeks.org/nearly-sorted-algorithm/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> sortKSortedArray(vector<int> &nums, int k){
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int i=0; i<=0+k; i++){
            min_heap.push(nums[i]);
        }
        nums[0] = min_heap.top();
        min_heap.pop();

        for(int i=1; i<nums.size(); i++){
            if(i+k < nums.size())
                min_heap.push(nums[i+k]);
            
            nums[i] = min_heap.top();
            min_heap.pop();
        }
    }

    void displayArray(vector<int> nums){
        for(auto ele: nums){
            cout<<ele<<" ";
        }cout<<"\n";
    }
};

int main(){
    vector<int> nums = {6, 5, 3, 2, 8, 10, 9};
    Solution obj;
    obj.sortKSortedArray(nums, 3);
    obj.displayArray(nums);

    nums = {10, 9, 8, 7, 4, 70, 60, 50};
    obj.sortKSortedArray(nums, 4);
    obj.displayArray(nums);
}