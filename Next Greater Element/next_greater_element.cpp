// https://www.youtube.com/watch?v=keDXgeyjysY&t=99s

#include<bits/stdc++.h>
using namespace std;

void NGE(vector<int> &nums){
    stack<int> s;
    stack<int> index_s;
    vector<int> result(nums.size());
    result[result.size()-1] = -1;
    int ind;
    for(int i=0; i<nums.size(); i++){
        if(s.empty() || s.top()>nums[i]){
            s.push(nums[i]);
            index_s.push(i);
        }else{
            while (s.empty()==false && s.top() < nums[i]){
                //cout<<"(3)"<<s.top()<<" "<<index_s.top()<<"\n";
                s.pop();
                ind = index_s.top();
                
                index_s.pop();
                
                result[ind] = nums[i];
            }
            
            s.push(nums[i]);
            index_s.push(i);
        }

    }
    for(auto num: result)
        cout<<num<<" ";
}

int main(){
    vector<int> nums = {11, 3, 7, 6, 11, 12};
    NGE(nums);
}