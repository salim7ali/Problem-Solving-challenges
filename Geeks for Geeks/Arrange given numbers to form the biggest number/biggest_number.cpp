// https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
// https://www.youtube.com/watch?v=qEIGhVtZ-sg

#include<bits/stdc++.h>
using namespace std;

class Number{
public:
    vector<int> getLargestNumber(vector<int> nums){
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                string str_A = to_string(nums[i]);
                string str_B = to_string(nums[j]);

                string str_A_B = str_A+str_B;
                string str_B_A = str_B+str_A;

                int A_B = stoi(str_A_B);
                int B_A = stoi(str_B_A);

                if(B_A > A_B){}
                    swap(nums[i], nums[j]);
            }
        }
    }
};

void dispVector(vector<int> nums){
    for(auto num: nums){
        cout<<num<<" ";
    }cout<<"\n";
}

int main(){
    vector<int> result;
    
    Number obj1;
    result = obj1.getLargestNumber({5, 6, 2, 9, 21, 1});
    
}