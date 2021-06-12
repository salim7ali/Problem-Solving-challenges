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
   for(int width=K; width<(int)A.size(); width*=count){
       for(int i=0; i+width<(int)A.size(); i++){
           int j= i+width;
           result += A[i]*A[j];
           cout<<result<<" ";
       }
       count +=1;
   }

   return result;
}

int main() {
    vector<int> nums = {2, 3, 5, 1, 5};
    cout<<"\n"<<solve_optimized(5, 4, nums);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // int T;
    // cin >> T;
    // for(int t_i = 0; t_i < T; t_i++)
    // {
    //     int N;
    //     cin >> N;
    //     int K;
    //     cin >> K;
    //     vector<int> A(N);
    //     for(int i_A = 0; i_A < N; i_A++)
    //     {
    //     	cin >> A[i_A];
    //     }

    //     long long out_;
    //     out_ = solve(N, K, A);
    //     cout << out_;
    //     cout << "\n";
    // }
}