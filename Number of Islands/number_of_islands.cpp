// https://www.youtube.com/watch?v=keDXgeyjysY&t=99s

#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, vector<vector<int>> &A){
    if(i>=0 && i<A.size() && j>=0 && j<A[0].size())
        return true;
    return false;
}

void BFS(vector<vector<int>> &A, int i, int j, int count){
    queue<pair<int, int>> Q;
    int adj[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
        A[i][j] = count;//marking as visited
    while (1){

        for(int k=0; k<8; k++){
            int x = i + adj[k][0];
            int y = j + adj[k][1];
            if(isValid(x, y, A) && A[x][y]==1){
                A[x][y] = count;//marking as visited
                Q.push({x, y});
            }
        }
        if(Q.empty() == false){
            i = Q.front().first;
            j = Q.front().second;
            Q.pop();
        }else// nothing left in Q to visit
            return;
    }
}

int noOfIslands(vector<vector<int>> &A){
    int count = 1;

    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[0].size(); j++){
            if(A[i][j] == 1){
                count += 1;
                BFS(A, i, j, count);
            }
        }
    }
    return count-1;
}

void showMatrix(vector<vector<int>> &mat){
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){
            cout<<mat[i][j]<<" ";
        }cout<<"\n";
    }
}
int main(){
    vector<vector<int>> mat = { {1, 1, 0, 0, 0},
                                {0, 1, 0, 0, 1},
                                {1, 0, 0, 1, 1},
                                {0, 0, 0, 0, 0},
                                {1, 0, 1, 0, 1}};
    showMatrix(mat);
    cout<<"\nNo of Islands: "<<noOfIslands(mat)<<"\n\n";
    showMatrix(mat);
}