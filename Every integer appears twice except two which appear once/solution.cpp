// https://www.youtube.com/watch?v=ZwU6wSkepBI&t=3408s

#include<bits/stdc++.h>
using namespace std;

class BitOperations{
    vector<int> nums;
public:
    BitOperations(vector<int> nums){
        this->nums = nums;
    }

    pair<int, int> uniquePairs(){
        int fullVectorXOR =0;

        for(int ele: nums){
            fullVectorXOR ^= ele;
        }
        // cout<<fullVectorXOR;

        int firstSetXOR=0;
        int secondSetXOR=0;
        for(int ele: nums){
            int firstHighBit = abs(~fullVectorXOR)+1;
            cout<<firstHighBit;
            if(ele&firstHighBit)
                firstSetXOR ^= ele;
            else
                secondSetXOR ^= ele;
        }

        return {firstSetXOR, secondSetXOR};
    }
};

int main(){
    vector<int> nums = {1, 1, 2, 5, 3, 2, 3, 4, 7, 4};
    pair<int, int> result;

    BitOperations obj1(nums);
    result = obj1.uniquePairs();
    cout<<result.first<<" "<<result.second<<"\n";
    
}