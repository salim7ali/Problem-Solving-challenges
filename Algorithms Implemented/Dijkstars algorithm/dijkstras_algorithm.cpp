// Dijkstra's algorithm using edge weight matrix
//         9
//     b --------c
//    / \ 2       \ 6
// 14/   f---------d
//  /   /|   11   /
// a---/9|      -
//  \    |10  /15
//   \   |   -
//  7 \  | /      
//     \ e



#include <bits/stdc++.h>
using namespace std;

int NO_OF_VERTICES =6;
//                                      a,       b,       c,       d,       e,       f
vector<vector<int>> weightMat =  {{       0,      14, INT_MAX, INT_MAX,       7,       9},//a
                                {      14,       0,       9, INT_MAX, INT_MAX,       2},//b
                                { INT_MAX,       9,       0,       6, INT_MAX, INT_MAX},//c
                                { INT_MAX, INT_MAX,       6,       0,       15,     11},//d
                                {       7, INT_MAX, INT_MAX,      15,        0,     10},//e
                                {       9,       2, INT_MAX,      11,       10,      0},//f
                                };

vector<int> minCost = {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
vector<bool> fixedNode = {0, 0, 0, 0, 0, 0};

int main(){
    int startVert= 0, u, nextVert, vertLeft;
    bool flag = false;
    fixedNode[startVert] = true;
    u = startVert;

    vertLeft = NO_OF_VERTICES;
    cout<<"Single source shortest path algorithm\nNode chosen order:\n";
    while(vertLeft--){
        cout<<char(u+97)<<" ";
        for(int i=0; i<NO_OF_VERTICES; i++){
            if(fixedNode[i] == false && weightMat[u][i] != INT_MAX){
                 
                //  setting nextVert to default unvisited vertex
                if(flag == false){
                    nextVert = i;
                    flag = true;
                }

                if(minCost[i]>minCost[u]+weightMat[u][i])
                    minCost[i] = minCost[u]+weightMat[u][i];
                if(minCost[i]<minCost[nextVert])
                    nextVert=i;
            }
        }
        flag = false;
        u = nextVert;
        fixedNode[nextVert] = true;
    }

    // output
    cout<<"\nSource "<<(char)(startVert+97)<<" to other nodes cost:\n";
    for(int i=0; i<minCost.size(); i++){
        cout<<(char)(i+97)<<"  ";
    }
    cout<<"\n";
    for(int i=0; i<minCost.size(); i++){
        cout<<minCost[i]<<" ";
    }
}