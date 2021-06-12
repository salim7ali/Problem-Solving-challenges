#include<bits/stdc++.h>
using namespace std;

long long solve (int N, int K, vector<int> A) {
   // Write your code here

   long long result = 0;
   for(int i=0; i<(int)A.size(); i++){
       for(int j=i+1; j<(int)A.size(); j++){
           if(i<j && ((j-i)%K==0)){
               result += A[i]*A[j];
           }
       }
   }

   return result;
}

long long solve_optimized(int N, int K, vector<int> A) {
   // Write your code here

   long long result = 0;
   int count = 1;
   for(int width=K; width<(int)A.size(); width=K*count){
       for(int i=0; i+width<(int)A.size(); i++){
           int j= i+width;
           result += A[i]*A[j];
           cout<<result<<" i:"<<i<<", j:"<<j<<"\n";
       }
       count +=1;
   }

   return result;
}

int main() {
    vector<int> nums = {7, 8, 2, 3, 1};
    // cout<<"\n"<<solve_optimized(5, 4, nums);

    // nums = {2, 3, 5, 1, 5, 2, 1, 3};
    cout<<"\n"<<solve_optimized(5, 3, nums);

}