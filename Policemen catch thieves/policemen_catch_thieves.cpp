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

    int maxThievesCaught(){

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