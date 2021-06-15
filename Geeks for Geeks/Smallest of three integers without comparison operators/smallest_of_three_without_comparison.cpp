// https://www.geeksforgeeks.org/smallest-of-three-integers-without-comparison-operators/
#include<bits/stdc++.h>
using namespace std;

class Comparison{
public:
    int smallerPair(int a, int b){
        if(a/b)    // a>b
            return b;
        else    // a<b
            return a;
    }

    int smallestOfThree(int a, int b, int c){
        
    }
}

int main(){
    Comparison obj;
    obj.smallestOfThree(5, 15, 4);
}