#include<bits/stdc++.h>
using namespace std;

class XOR_Operations{
    vector<int> nums;
public:
    XOR_Operations(vector<int> nums){
        this->nums = nums;
    }
    int xorOfSubsets(){
        return 0;
    }

};

int main(){
    vector<int> nums = {1, 3, 2};

    XOR_Operations obj1(nums);
    cout<<obj1.xorOfSubsets();
}