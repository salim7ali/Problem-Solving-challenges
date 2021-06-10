// https://www.youtube.com/watch?v=4tYoVx0QoN0&t=158s

#include<bits/stdc++.h>
using namespace std;

class Islands{
public:
    void removeIslands(vector<vector<int>> matrix){

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
    obj.removeIslands(matrix);
}