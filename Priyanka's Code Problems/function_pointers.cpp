










// #include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int numArray[] = {4, 5, 23, 4, 36};
    int SIZE = *(&numArray+1) - numArray;
    int *ptrToArr = numArray; 
    
    cout<<numArray<<"\t"<<numArray+1<<"\n";
    cout<<&numArray<<"\t"<<&numArray+1<<"\n";
    cout<<&numArray[0]<<"\t"<<&numArray[0]+1<<"\n";
    cout<<ptrToArr<<"\t"<<ptrToArr+1<<"\n";

    cout<<"-------\n";
    // NOTE: printing one element beyond array SIZE
    for(int i=0; i<=SIZE; i++)
        cout<<ptrToArr+i<<" "<<*(ptrToArr+i)<<"\n";
}