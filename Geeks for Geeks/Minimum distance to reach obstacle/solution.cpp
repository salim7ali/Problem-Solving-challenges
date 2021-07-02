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

    bool isValidNeighbour(int neigh_i, int neigh_j){
        if(matrix[neigh_i][neigh_j] !=0 && neigh_i>=0 && neigh_i<matrix.size() && neigh_j>=0 && neigh_j<matrix[0].size())
            return true;
        return false;
    }
    
    void dfs(int i, int j, vector<vector<bool>> &visited, int currDist, int &minDist){
        if(matrix[i][j] == 9 && currDist<minDist)
            minDist = currDist;

        currDist += 1;
        visited[i][j] = true;


        for(int k=0; k<4; k++){
            int neigh_i = i + neighbours[k][0];
            int neigh_j = j + neighbours[k][1];
            
            if(isValidNeighbour(neigh_i, neigh_j) && visited[neigh_i][neigh_j]==false)
                dfs(neigh_i, neigh_j, visited);
        }

        // When returning from node, reset the visited state
        visited[i][j] = false;
    }
    
    int shortestDistToObstacle(){
        vector<vector<bool>> visited(matrix.size(), vector<bool> (matrix[0].size(), false));
        int minDist =INT_MAX;
        int currDist = 0;

        dfs(0, 0, visited, currDist, minDist);
        return minDist;
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