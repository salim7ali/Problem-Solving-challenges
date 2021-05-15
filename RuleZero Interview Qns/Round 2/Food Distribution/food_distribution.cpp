#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int FoodDistribution(vector<int> arr){
    int sandwiches=arr[0];

    vector<int> hungry = arr;
    hungry.erase(hungry.begin());

    // hunger can be minimized to possible hunger average which may be a fraction
    float possible_hunger_avg=0;
    int max_hunger = 0;
    for(int i=0; i<hungry.size(); i++){
        max_hunger += hungry[i];
    }
    int min_hunger = max_hunger - sandwiches;
    possible_hunger_avg = ceil(min_hunger/hungry.size());
    cout<<possible_hunger_avg<<"\n";

    vector<int> result_hungry = hungry;
    int i=0;
    while(sandwiches != 0){
        if(result_hungry[i] >possible_hunger_avg) {
            int curr_reducible_hunger = result_hungry[i] - possible_hunger_avg;
            if(sandwiches >= curr_reducible_hunger){
                sandwiches -= curr_reducible_hunger;
                result_hungry[i] -= curr_reducible_hunger;
            }else{
                result_hungry[i] -= sandwiches;
                // sandwiches =0;
                break;
            }

        }
    }

    // disp result
    for(int i=0; i<result_hungry.size(); i++){
        cout<<result_hungry[i]<<" ";
    }
}

int main(){
    // cout<<FoodDistribution({5, 3, 1, 2, 1})<<"\n";
    cout<<FoodDistribution({4, 5, 2, 3, 1, 0})<<"\n";
    // cout<<FoodDistribution({5, 2, 3, 4, 5})<<"\n";
    // cout<<FoodDistribution({3, 2, 1, 0, 4, 1, 0})<<"\n";
}