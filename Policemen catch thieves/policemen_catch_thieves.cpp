// https://www.youtube.com/watch?v=MFkqnGiCCiU&t=1703s
// https://www.geeksforgeeks.org/policemen-catch-thieves/

#include<bits/stdc++.h>
using namespace std; 

class CatchThieves{
    vector<char> police_thief;
    int k;
public:
    CatchThieves(vector<char> police_thief, int k){
        this->police_thief = police_thief;
        this->k = k;
    }

    void findNext(int &curr_index, char thief_or_police, vector<char> &police_thief){
        int i; 
        if(thief_or_police == 'P'){
            for(i=curr_index+1; i<police_thief.size(); i++){
                if(police_thief[i] == 'P'){
                    curr_index = i;
                    return;
                }
            }
            curr_index = INT_MAX;
        }else if(thief_or_police == 'T'){
            for(i=curr_index+1; i<police_thief.size(); i++){
                if(police_thief[i] == 'T'){
                    curr_index = i;
                    return;
                }
            }
            curr_index = INT_MAX;
        }
    }

    int maxThievesCaught(){
        int police_index = INT_MIN;
        int thief_index = INT_MIN;

        // finding first instances of police and thief from left side
        for(int i=0; i<police_thief.size(); i++){
            if(police_index != INT_MIN && thief_index != INT_MIN)
                break;
            if(police_thief[i] == 'P' && police_index == INT_MIN)
                police_index = i;
            if(police_thief[i] == 'T' && thief_index == INT_MIN)
                thief_index = i;
        }

        int maxCaught =0;
        while(police_index < police_thief.size() && thief_index < police_thief.size()){
            if(abs(police_index - thief_index) <= k){
                maxCaught += 1;
                findNext(police_index, 'P', police_thief);
                findNext(thief_index, 'T', police_thief);
            }else{
                if(police_index < thief_index)
                    findNext(police_index, 'P', police_thief);
                else  //police_index > thief_index
                    findNext(thief_index, 'T', police_thief);
            }
        }
        return maxCaught;
    }
};

int main(){
    vector<char> police_thief;

    police_thief = {'P', 'T', 'T', 'P', 'T'};
    CatchThieves obj1(police_thief, 1);    
    cout<<obj1.maxThievesCaught()<<"\n";
    
    police_thief = {'T', 'T', 'P', 'P', 'T', 'P'};
    CatchThieves obj2(police_thief, 2);    
    cout<<obj2.maxThievesCaught()<<"\n";

    police_thief = {'P', 'T', 'P', 'T', 'T', 'P'};
    CatchThieves obj3(police_thief, 3);    
    cout<<obj3.maxThievesCaught()<<"\n";
}