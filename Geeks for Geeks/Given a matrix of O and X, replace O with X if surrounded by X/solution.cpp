// Given a matrix where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’. A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it. 
// https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/
#include<bits/stdc++.h>
using namespace std;

class Matrix{
    vector<vector<char>> matrix;
public:
    Matrix(vector<vector<char>> matrix){
        this->matrix = matrix;
    }

    void replaceO(){
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int j=0; j<cols-1; j++)
            if(matrix[0][j] == 'O')
                dfs(0, j);
        for(int i=1; i<rows-1; i++)
            if(matrix[i][cols-1] == 'O')
                dfs(i, cols-1);
        for(int j=0; j<cols-2; j++)
            if(matrix[rows-1][j] == 'O')
                dfs(rows-1, j);
        for(int i=1; i<rows-2; i++)
            if(matrix[i][0] == 'O')
                dfs(i, 0);
    }
};

int main(){
    vector<vector<char>> matrix = {  {'X', 'O', 'X', 'X', 'X', 'X'},
                                    {'X', 'O', 'X', 'X', 'O', 'X'},
                                    {'X', 'X', 'X', 'O', 'O', 'X'},
                                    {'O', 'X', 'X', 'X', 'X', 'X'},
                                    {'X', 'X', 'X', 'O', 'X', 'O'},
                                    {'O', 'O', 'X', 'O', 'O', 'O'},
                                    };
    Matrix obj(matrix);
    
}