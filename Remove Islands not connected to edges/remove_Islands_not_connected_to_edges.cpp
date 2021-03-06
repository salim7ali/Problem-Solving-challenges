// https://www.youtube.com/watch?v=4tYoVx0QoN0&t=158s
// Remove all black pixels not connected to border of image

#include<bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> &matrix){
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }cout<<"\n";
    }
    cout<<"\n";
}

// 1 -> black
// 0 -> white
class Islands{
public:
    bool isValid(int i, int j, vector<vector<int>> &matrix){
        if(i>=0 && i<matrix.size()-1 && j>=0 && j<matrix[0].size()-1)
            return true;
        return false;
    }

    void dfs(int i, int j, vector<vector<int>> &matrix){
        matrix[i][j] += 1;
        
        int neighbours[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int neighIndex=0; neighIndex<4; neighIndex++){
            int neighbourRow = i+neighbours[neighIndex][0]; 
            int neighbourCol = j+neighbours[neighIndex][1];
            if(isValid(neighbourRow, neighbourCol, matrix) && matrix[neighbourRow][neighbourCol]==1 )
                dfs(neighbourRow, neighbourCol, matrix);
        }
    }

    vector<vector<int>> removeIslands(vector<vector<int>> matrix){
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                int first_row = 0;
                int last_row = matrix.size()-1;
                int first_col = 0;
                int last_col = matrix[0].size()-1;
                
                if((i==first_row || i==last_row || j==first_col || j==last_col) && matrix[i][j]==1){
                    dfs(i, j, matrix);
                }
            }
        }
        
        // displayMatrix(matrix);
        
        // removing black pixels
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 2)
                    matrix[i][j] = 1;
                else if(matrix[i][j] == 1)
                    matrix[i][j] = 0;
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
    displayMatrix(matrix);
    
    Islands obj;
    vector<vector<int>> resultMatrix = obj.removeIslands(matrix);
    displayMatrix(resultMatrix);

}