#include<bits/stdc++.h>
using namespace std;

class Islands
{
private:
    //                                      T,      R,      B,      L
    vector<pair<int, int>> neighbours = {{-1, 0}, {0, 1},{1, 0},{0, -1}}; 
public:
    Islands(){
    }

    void dfs(vector<vector<int>> &terrain, int row, int col, int &islandCount){
        terrain[row][col] = INT_MIN;

        for(int k=0; k<4; k++){
            pair<int, int> currNeighbourPosition = this->neighbours[k];
            pair<int, int> currNeighbour = {row+currNeighbourPosition.first, col+currNeighbourPosition.second};

            if(isValidRowCol(terrain, currNeighbour.first, currNeighbour.second) && terrain[currNeighbour.first][currNeighbour.second] == 1){
                dfs(terrain, currNeighbour.first, currNeighbour.second, islandCount);
            }
        }
    }

    bool isValidRowCol(vector<vector<int>> &terrain, int i, int j){
        if(i>=0 && i<terrain.size() && j>=0 && j<terrain[0].size())
            return true;
        return false;
    }

    int determineIslandCount(vector<vector<int>> &terrain){
        int islandCount =0;
        
        for(int i=0; i<terrain.size(); i++){
            for(int j=0; j<terrain[0].size(); j++){
                if(terrain[i][j] == 1){     // Island
                    islandCount += 1;
                    dfs(terrain, i, j, islandCount);
                }
            }
        }
        return islandCount;
    }
};

int main(){
    vector<vector<int>> terrain;
    terrain.push_back({0, 1, 1, 0});
    terrain.push_back({0, 1, 0, 0});
    terrain.push_back({0, 0, 1, 0});
    terrain.push_back({1, 0, 1, 0});
    
    Islands* obj = new Islands();

    cout<<obj->determineIslandCount(terrain);

    return 0;
}
