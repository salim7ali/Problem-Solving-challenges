// Given a matrix where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’. A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it. 
// https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/
#include<bits/stdc++.h>
using namespace std;

class Matrix{
    vector<vector<char>> matrix;
    int neighbourDirections[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void dfs(int i, int j){
        // if(matrix[i][j] != 'O')
        //     return;

        matrix[i][j] = '1';

        for(int k=0; k<4; k++){
            int neighRow = i + neighbourDirections[k][0];
            int neighCol = j + neighbourDirections[k][1];
            if(isValid(neighRow, neighCol) && matrix[neighRow][neighCol] == 'O')
                dfs(neighRow, neighCol);
        }
    }

    bool isValid(int i, int j){
        if(i>=0 && i<matrix.size()-1 && j>=0 && j<matrix[0].size())
            return true;
        return false;
    }

public:
    Matrix(vector<vector<char>> matrix){
        this->matrix = matrix;
    }

    void replaceO(){
        
        // top row
        for(int j=0; j<matrix[0].size(); j++)
            if(matrix[0][j] == 'O')
                dfs(0, j);
        // this->displayMatrix();
        
        // rightmost col
        for(int i=1; i<matrix.size(); i++)
            if(matrix[i][matrix[0].size()-1] == 'O')
                dfs(i, matrix[0].size()-1);
        // this->displayMatrix();
        
        // bottom row
        for(int j=0; j<matrix[0].size()-1; j++)
            if(matrix[matrix.size()-1][j] == 'O')
                dfs(matrix.size()-1, j);
        // this->displayMatrix();

        // leftmost col
        for(int i=1; i<matrix.size()-1; i++)
            if(matrix[i][0] == 'O')
                dfs(i, 0);
        // this->displayMatrix();
        
        // setting final output
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == '1')
                    matrix[i][j] = 'O';
                else if(matrix[i][j] == 'O')
                    matrix[i][j] = 'X';
            }
        }
    }

    void displayMatrix(){
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                cout<<matrix[i][j]<<" ";
            }cout<<"\n";
        }
        cout<<"\n";
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
    obj.displayMatrix();
    obj.replaceO();
    obj.displayMatrix();
    
}