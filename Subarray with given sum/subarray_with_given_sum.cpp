#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int subarrWithSum(vector<int> nums, int &SUM, int &start, int &end){
    int currSum =0;
    int j;
    
    for(int i=0; i<nums.size(); i++){
        j=i;
        while(j<nums.size()){
            if(i==j)
                currSum = nums[i];
            else
                currSum += nums[j];
                
            if(currSum == SUM){
                start = i;
                end =j;
                return 0;
            }else if(currSum>SUM){
                currSum -= nums[i];
                continue;
            }else//currSum<SUM
                j++;
        }
    }
    return -1;
}

int main() {
    int T, N, S, num, start, end, found;
    
    vector<int> nums;
    cin>>T;
	while(T--){
	    cin>>N;
	    cin>>S;
	    for(int i=0; i<N; i++){
	        cin>>num;
	        nums.push_back(num);
	    }
	    found = subarrWithSum(nums, S, start, end);
	    if(found == -1)
	        cout<<found<<"\n";
	    else
	        cout<<start+1<<" "<<end+1<<"\n";
	   found = 0;
	   nums.clear();
	}
	return 0;
}