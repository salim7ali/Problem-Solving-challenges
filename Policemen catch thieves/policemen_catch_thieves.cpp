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

    void findNext(int &currIndex, char thief_of_police, vector<char> &police_thief){
        int i; 
        if(thief_of_police == 'P'){
            for(i=currIndex+1; i<police_thief.size(); i++){
                if(police_thief[i] == 'P'){
                    currIndex = i;
                    return;
                }
            }
            currIndex = INT_MAX;
        }else if(thief_of_police == 'T'){
            for(i=currIndex+1; i<police_thief.size(); i++){
                if(police_thief[i] == 'T'){
                    currIndex = i;
                    return;
                }
            }
            currIndex = INT_MAX;
        }
    }

    int maxThievesCaught(){
        int policeIndex = INT_MIN;
        int thiefIndex = INT_MIN;

        // finding first instances of police and thief from left side
        for(int i=0; i<police_thief.size(); i++){
            if(policeIndex != INT_MIN && thiefIndex != INT_MIN)
                break;
            if(police_thief[i] == 'P' && policeIndex == INT_MIN)
                policeIndex = i;
            if(police_thief[i] == 'T' && thiefIndex == INT_MIN)
                thiefIndex = i;
        }

        int maxCaught =0;
        while(policeIndex < police_thief.size() && thiefIndex < police_thief.size()){
            if(abs(policeIndex-thiefIndex) <= k){
                maxCaught += 1;
                findNext(policeIndex, 'P', police_thief);
                findNext(thiefIndex, 'T', police_thief);
            }else{
                if(policeIndex < thiefIndex)
                    findNext(policeIndex, 'P', police_thief);
                else  //policeIndex > thiefIndex
                    findNext(thiefIndex, 'T', police_thief);
            }
        }

        
    }
}

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