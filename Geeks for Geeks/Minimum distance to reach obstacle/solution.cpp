// https://www.geeksforgeeks.org/amazon-interview-experience-for-sde-1-13/
#include<bits/stdc++.h>
using namespace std;

class DemolitionRobot{
    vector<vector<int>> matrix;
    int neighbours[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    DemolitionRobot(vector<vector<int>> matrix){
        this->matrix = matrix;
    }

    bool isValid(int neigh_i, int neigh_j){
        if(neigh_i>=0 && neigh_i<matrix.size() && neigh_j>=0 && neigh_j<matrix[0].size())
            return true;
        return false;
    }
    
    void dfs(int i, int j, vector<vector<bool>> visited){
        visited[i][j] = true;

        for(int k=0; k<4; k++){
            int neigh_i = i + neighbours[k][0];
            int neigh_j = j + neighbours[k][1];
            
            if(isValid(neigh_i, neigh_j) && visited[i][j]){

            }
        }

    }
    
    int shortestDistToObstacle(){
        vector<vector<bool>> visited(matrix.size(), vector<bool> (matrix[0].size(), false));

        dfs(0, 0, visited);
        return 0;
    }

};

int main(){
    vector<vector<int>> matrix={
    {1, 0, 0},
    {1, 0, 0},
    {1, 9, 1}};

    DemolitionRobot obj(matrix);
    cout<<obj.shortestDistToObstacle()<<"\n";
}