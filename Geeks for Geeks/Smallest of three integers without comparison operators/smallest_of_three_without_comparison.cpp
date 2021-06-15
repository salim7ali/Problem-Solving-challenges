// https://www.geeksforgeeks.org/smallest-of-three-integers-without-comparison-operators/
// Assuming positive distinct numbers
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
        int currSmall = smallerPair(a, b);

        return smallerPair(currSmall, c);
    }
};

int main(){
    Comparison obj1;
    cout<<obj1.smallestOfThree(5, 15, 4)<<"\n";

    Comparison obj2;
    cout<<obj2.smallestOfThree(12, 15, 5)<<"\n";

    Comparison obj3;
    cout<<obj3.smallestOfThree(78, 88, 68)<<"\n";

    return 0;
}