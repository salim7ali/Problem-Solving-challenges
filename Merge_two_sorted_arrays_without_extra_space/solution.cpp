// https://www.youtube.com/watch?v=r3pMQ8-Ad5s&list=LL&index=9
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void merge2SortedArrays(vector<int> &arr1, vector<int> &arr2){
        int arr1CurrInd = arr1.size()-1;
        int arr2CurrInd = 0;
        while (arr1CurrInd>=0 && arr2CurrInd<arr2.size())
        {
            if(arr1[arr1CurrInd]>arr2[arr2CurrInd]){
                swap(arr1[arr1CurrInd], arr2[arr2CurrInd]);
                arr1CurrInd -=1;
                arr2CurrInd +=1;
            }else{
                break;
            }
        }
        sort(arr1.begin(), arr1.begin()+arr1.size());
        sort(arr2.begin(), arr2.begin()+arr2.size());
    }
};

int main(){
    vector<int> arr1 ={1, 3, 5, 7};
    vector<int> arr2 ={0, 2, 6, 8, 9};

    Solution obj;
    obj.merge2SortedArrays(arr1, arr2);

    return 1;
}