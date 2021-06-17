// https://www.geeksforgeeks.org/microsoft-interview-experience-8-years-experienced/
// Rotate 2d array clockwise and anti clock wise 90 degrees.2d array need not be square

#include<bits/stdc++.h>
using namespace std;

class Matrix{
public:
    vector<vector<int>> rotateClockwise90(vector<vector<int>> matrix){
        // switching for rotated matrix
        int rotated_row = matrix[0].size();
        int rotated_col = matrix.size();

        vector<vector<int>> rotated_matrix;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                int rotated_curr_row = matrix[0].size() - j -1;
                int rotated_curr_col = matrix.size() - i -1; 

                rotated_matrix[rotated_curr_row][rotated_curr_col] = matrix[i][j];
            }
        }
        return rotated_matrix;
    }

    vector<vector<int>> rotateAntiClockwise90(){

    }

    void dispMatrix(vector<vector<int>> matrix){

    }
}

int main(){
    
    vector<vector<int>> matrix;
    
    Matrix obj(matrix);
    vector<vector<int>> result;
    result = obj.rotateAntiClockwise90();
    obj.rotateAntiClockwise90();
}