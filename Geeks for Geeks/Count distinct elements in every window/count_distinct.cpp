// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1


#include<bits/stdc++.h>
using namespace std;

class Window{
    vector<int> nums;
public:
    Window(vector<int> nums){
        this->nums = nums;
    }

    vector<int> countDistinct(int k){
        
        int curr_distinct_count = 0;
        map<int, int> count;
        
        for(int i=0; i<k; i++){
            count[nums[i]] += 1;

            if(count[nums[i]] == 1)
                curr_distinct_count +=1;
            if(count[nums[i]] == 2)
                curr_distinct_count -=1;
        }
        vector<int> result;
        result.push_back(curr_distinct_count);


        for(int i=1; i+k-1<nums.size(); i++){
            int exit_num = nums[i-1];
            int entry_num = nums[i+k-1];

            if(entry_num != exit_num){
                count[entry_num] += 1;
                if(count[entry_num] == 1)
                    curr_distinct_count +=1;
                if(count[entry_num] == 2)
                    curr_distinct_count -=1;

                count[exit_num] -= 1;
                if(count[exit_num] == 1)
                    curr_distinct_count +=1;
                if(count[exit_num] == 0)
                    curr_distinct_count -=1;
            }


            result.push_back(curr_distinct_count);
        }
        return result;
    }
};

void display(vector<int> nums){
    for(auto num: nums){
        cout<<num<<" ";
    }cout<<"\n";
}

int main(){
    // vector<int> nums = {1,2,1,3,4,2,3};
    vector<int> nums = {1, 2, 2, 1, 3, 1, 1, 3};
    vector<int> result;

    Window obj(nums);
    result = obj.countDistinct(4);
    display(result);

    
}