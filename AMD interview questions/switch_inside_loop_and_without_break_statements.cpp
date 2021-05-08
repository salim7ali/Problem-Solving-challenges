// #include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
    for(int i=0; i<20; i++){
        switch(i){
            case 1: i += 5;
            case 2: i += 2;
            case 3: i += 5;
            default:
            i += 4;
            break;
        }
        cout<<i<<"\n";
    }
}