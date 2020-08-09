// https://www.geeksforgeeks.org/a-product-array-puzzle/
// I have only used above link to refer the problem statement and not the solution

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> numbers  = {10, 3, 5, 6, 2};
    vector<int> lTor_Prod(numbers.size(), 0);
    vector<int> rTol_Prod(numbers.size(), 0);
    vector<int> result(numbers.size(), 0);
    int lTor_currProd = 1;
    int rTol_currProd = 1;

    for(int i=0; i<numbers.size(); i++){
        // going left to right
        lTor_currProd *= numbers[i];
        lTor_Prod[i] = lTor_currProd;

        // goind right to left
        rTol_currProd *= numbers[numbers.size()-i-1];
        rTol_Prod[numbers.size()-i-1] = rTol_currProd;
    }

    for(int i=0; i<numbers.size(); i++){
        if(i>0 && i<numbers.size()-1)
            result[i] = lTor_Prod[i-1] * rTol_Prod[i+1];
        else if(i==0)
            result[i] = rTol_Prod[i+1];
        else
            result[i] = lTor_Prod[i-1];
    }

    // output:
    cout<<"Input vector: ";
    for(int i=0; i<numbers.size(); i++){
        cout<<numbers[i]<<" ";
    }
    cout<<"\nResult vector: ";
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}