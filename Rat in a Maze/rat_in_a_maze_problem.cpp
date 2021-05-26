#include<bits/stdc++.h>
using namespace std;

#define v2d vector<vector<int>>


class MazeSolver{
    v2d maze;
    v2d currently_visited;

    pair<int, int> START_INDICES = {0, 0};
    pair<int, int> END_INDICES;
    
    vector<pair<int, int>> directions= {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    MazeSolver(v2d &maze){
        this->maze = maze;

        this->END_INDICES = {maze.size()-1, maze[0].size()-1};

        this->currently_visited = maze;
        for(int i=0; i<this->currently_visited.size(); i++)
            for(int j=0; j<this->currently_visited[0].size(); j++)
                this->currently_visited[i][j] =0;
    }

    bool isValidNode(int i, int j, int rows, int cols){
        if(i>=0 && i<rows && j>=0 && j<cols)
            return true;
        return false;
    }

    int dfs_path(){
        
    }

};

int main(){
    v2d grid = {{1, 1, 1},
                                {1, 1, 0},
                                {1, 1, 1}};
    MazeSolver obj(grid);
    obj.dfs_path();

}