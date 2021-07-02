// https://www.geeksforgeeks.org/amazon-interview-experience-for-sde-1-13/
#include<bits/stdc++.h>
using namespace std;

class DemolitionRobot{
    vector<vector<int>> matrix;
public:
    DemolitionRobot(vector<vector<int>> matrix){
        this->matrix = matrix;
    }

    int shortestDistToObstacle(){

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