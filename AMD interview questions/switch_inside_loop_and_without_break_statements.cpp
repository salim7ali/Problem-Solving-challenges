// #include<bits/stdc++.h>
#include<iostream>

using namespace std;

void switchWithoutBreak(){
    for(int i=0; i<20; i++){
        switch(i){
            case 0: i += 5;
            case 1: i += 2;
            case 2: i += 5;
            default:
            i += 4;
            break;
        }
        cout<<i<<"\n";
    }
}

int main(){
    switchWithoutBreak();
    return 0;
}