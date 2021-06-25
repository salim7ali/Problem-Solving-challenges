// https://www.geeksforgeeks.org/amazon-interview-experience-13/
#include<bits/stdc++.h>
using namespace std;

class Restaurants{
    vector<pair<int, int>> location;
public:
    Restaurants(vector<pair<int, int>> location){
        this->location = location;
    }

    float getDistance(float x1, float y1){
        return sqrt((x1*x1) + (y1*y1)) ;
    }


    vector<pair<int, int>> nearestRestarurants(int X){
        // priority_queue<float, vector<float>, greater<float>> min_heap;
        set< pair<float, pair<float, float>> > minDistSet;

        for(int i=0; i<location.size(); i++){
            float distance = getDistance(location[i].first, location[i].second); 
            pair<int, int> restaurantCoordinate = {location[i].first, location[i].second};
            minDistSet.insert({distance, restaurantCoordinate});
        }

        vector<pair<int, int>> result;
        auto it = minDistSet.begin();
        for(int i=0; i<X; i++){
            cout<<it->second.first<<it->second.second<<"\n";


            it++;
        }
        return result;
    }
};

int main(){
    vector<pair<int, int>> location = {{1, 2}, {3, 4}, {1, -1}};
    Restaurants obj(location);
    vector<pair<int, int>> result = obj.nearestRestarurants(2);

}