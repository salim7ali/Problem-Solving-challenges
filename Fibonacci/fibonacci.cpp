#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    if(n==1)
        return 1;
    else if(n==0)
        return 0;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n = 6;//6th fibonacci number
    
    cout<<fibonacci(n);
}