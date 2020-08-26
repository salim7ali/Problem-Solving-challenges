// https://www.youtube.com/watch?v=dyrRM8dTEus&t=107s
// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int GCD(int first, int second){
    if(second == 0)
        return first;
    return GCD(second, first%second); 
}

int main(){
    int first = 27;
    int second = 15;
    cout<<"GCD of "<<first<<" and "<<second<<" = "<<GCD(first, second);
}