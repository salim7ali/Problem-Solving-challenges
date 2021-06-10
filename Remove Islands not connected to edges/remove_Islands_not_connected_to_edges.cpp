// https://www.youtube.com/watch?v=4tYoVx0QoN0&t=158s
// Remove all black pixels not connected to border of image

#include<bits/stdc++.h>
using namespace std;

// 1 -> black
// 0 -> white
class Islands{
public:
    void dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<bool>> &visited){
        visited[i][j] = true;
        
        int neighbours[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int )
        if(visited[i][j] )
    }

    vector<vector<int>> removeIslands(vector<vector<int>> matrix){
        vector<vector<bool>> visited(matrix.size(), vector<int> (matrix[0].size(), false));
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                int first_row = 0;
                int last_row = matrix.size()-1;
                int first_col = 0;
                int last_col = matrix[0].size()-1;
                
                if((i==first_row || i==last_row || j==first_col || j==last_col) && matrix[i][j]==1){
                    dfs(i, j, matrix, visited);
                }
            }
        }



        return matrix;
    }
};

int main(){
    vector<vector<int>> matrix ={
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 0},
        {1, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 1},
    };
    
    Islands obj;
    vector<vector<int>> resultMatrix = obj.removeIslands(matrix);
}