#include <bits/stdc++.h>
#include <algorithm>//copy() and assign()
#include <vector>//erase()
using namespace std;
const int INIT_NODE = 0;
//                               a   b   c   d
vector<vector <int>> costMat = {{ 0, 10, 15, 20},//a
                                {10,  0,  9, 10},//b
                                {15,  9,  0, 12},//c
                                {20, 10, 12,  0}};//d

vector<int> resNodes;

int T(int curNode, vector<int> remNodes){
    int minCost = 999999;//set to infinity
    int minNode;
    vector<int> subNodes;

    if(remNodes.size() == 0)
        return costMat[curNode][INIT_NODE];
    for(int i=0; i<remNodes.size(); i++){
        subNodes.assign(remNodes.begin(), remNodes.end());
        subNodes.erase(subNodes.begin() + i);

        if(minCost > costMat[curNode][remNodes[i]] + T(remNodes[i], subNodes)){
            minCost = costMat[curNode][remNodes[i]] + T(remNodes[i], subNodes);
            minNode = remNodes[i];
        }
        subNodes.clear();
    }
    resNodes.push_back(minNode);
    return minCost;
}

int main(){
    vector<int> initNodes = {1, 2, 3};
    cout<<T(INIT_NODE, initNodes)<<"\n";
    // for(int i=0; i<resNodes.size(); i++){
    //     cout<<resNodes[i]<<" ";
    // }
    
    
    return 0;
}