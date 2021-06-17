// https://www.geeksforgeeks.org/microsoft-interview-experience-8-years-experienced/
// Rotate 2d array clockwise and anti clock wise 90 degrees.2d array need not be square

#include<bits/stdc++.h>
using namespace std;

class Matrix{
public:
    vector<vector<int>> matrix;
    Matrix(vector<vector<int>> matrix){
        this->matrix = matrix;
    }

    vector<vector<int>> rotateClockwise90(){
        // switching for rotated matrix
        int rotated_row_size = this->matrix[0].size();
        int rotated_col_size = this->matrix.size();

        vector<vector<int>> rotated_matrix(rotated_row_size, vector<int> (rotated_col_size));
        for(int i=0; i<this->matrix.size(); i++){
            int rotated_curr_col = rotated_col_size - i -1; 
            for(int j=0; j<this->matrix[0].size(); j++){
                int rotated_curr_row = j;

                rotated_matrix[rotated_curr_row][rotated_curr_col] = this->matrix[i][j];
            }
        }
        return rotated_matrix;
    }

    // vector<vector<int>> rotateAntiClockwise90(){

    // }

    void dispMatrix(vector<vector<int>> matrix){
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                cout<<matrix[i][j]<<" ";
            }cout<<"\n";
        }cout<<"\n";
    }
};

int main(){
    
    vector<vector<int>> matrix ={
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
    };
    
    Matrix obj(matrix);
    vector<vector<int>> result;
    
    obj.dispMatrix(matrix);
    result = obj.rotateClockwise90();
    obj.dispMatrix(result);
    // obj.rotateAntiClockwise90();

    // obj.dispMatrix(obj.matrix);
    

    return 0;
}