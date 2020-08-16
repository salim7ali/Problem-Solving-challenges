// https://www.youtube.com/watch?v=C6aM_QpXco4
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    // vector<int> balloon = {5, 4, 4, 3, 3};
    vector<int> balloon = {6, 4, 6, 3, 9, 3};
    vector<int> arrows;
    int arrCount = 0;
    bool found = false;
    for(int i=0; i<balloon.size(); i++){
        for(int j=0; j<arrows.size(); j++){
            if(arrows[j] > 0){
                arrows[j] -= 1;
            }else{
                arrows.erase(arrows.begin()+j);
            }
            if(balloon[i] == arrows[j])
                found = true;
        }
        if(found == false){
            arrows.push_back(balloon[i]);
            arrCount += 1;
            cout<<balloon[i]<<" ";
        }
        found = false;
    }

    cout<<"\nNo arrows: "<<arrCount;
}