#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long long num){
    // num should always be long long. Sometimes int might get passed

    long long sqrtNum = sqrt(num);
    // cout<<num<<" "<<sqrtNum<<" "<<sqrtNum*sqrtNum<<"\n";
    if(sqrtNum*sqrtNum == num)
        return true;
    return false;
}

long long countTriplets(int N, vector<int> A){
    long long count =0;
    
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A.size(); j++){
            for(int k=0; k<A.size(); k++){
                long long prod = (long long)A[i]*(long long)A[j]*(long long)A[k];
                if(isPerfectSquare(prod)){
                    count += 1;   
                }
            }
        }
    }
    return count;
}

int main(){
    vector<int> nums = {3, 6, 2};
    cout<<countTriplets(3, nums)<<"\n";

    nums = {1, 2, 3};
    cout<<countTriplets(3, nums)<<"\n";
}