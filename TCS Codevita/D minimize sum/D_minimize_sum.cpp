#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arrList;
    int temp;

    cin>>N>>K;
    for(i=0; i<N; i++){
        cin>>temp;
        arrList.push_back(temp);
    }

    for(i=0; i<K; i++){
        maxInd = distance(arrList, max_element(arrList, arrList + arrList.size()));
        arrList[maxInd] = floor(arrList[maxInd]/2);
    }

    cout<<sum(arrList);
    return 0;
}