// Given an integer, find the total number of set bits, first and the last set bit

#include<bits/stdc++.h>
using namespace std;

class NumberOps{
    int num;
public:
    NumberOps(int num){
        this->num = num;
    }

    int getNumberOfSetBits(){
        int currNum = num;
        int totalSetBits = 0;
        while(currNum){
            currNum = currNum & (currNum-1);
            totalSetBits += 1;
        }
        return totalSetBits;
    }

    int getFirstSetBitPosition(){
        return log2(num & ((~num)+1));
    }

    int getLastSetBitPosition(){
        return log2(num);
    }
};

int main(){
  NumberOps obj1(13);  
  cout<<obj1.getNumberOfSetBits()<<"\n";
  cout<<obj1.getFirstSetBitPosition()<<"\n";
  cout<<obj1.getLastSetBitPosition()<<"\n\n";

  NumberOps obj2(64);  
  cout<<obj2.getNumberOfSetBits()<<"\n";
  cout<<obj2.getFirstSetBitPosition()<<"\n";
  cout<<obj2.getLastSetBitPosition()<<"\n";
}