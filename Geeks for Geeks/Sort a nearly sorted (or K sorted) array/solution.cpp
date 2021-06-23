// https://www.youtube.com/watch?v=tJK7vjNKdLY&t=24s
// https://www.geeksforgeeks.org/nearly-sorted-algorithm/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> sortKSortedArray(vector<int> nums){

    }

    void displayArray(vector<int> nums){
        for(auto ele: nums){
            cout<<ele<<" ";
        }cout<<"\n";
    }
}

int main(){
    vector<int> nums = {6, 5, 3, 2, 8, 10, 9};
    Solution obj;
    vector<int> result = obj.sortKSortedArray();
    obj.displayArray(result);
}