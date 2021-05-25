// https://www.youtube.com/watch?v=mDYOy7k8kOQ
#include<bits/stdc++.h>
using namespace std;

class RiverCrossing{
    // instance variables
    int ROCKS;
private:
    RiverCrossing(int rocks){
        this->ROCKS = rocks;
    }
    int get_no_of_ways(){
        if(ROCKS==1)
            return 2;

        int step_position = 0;
        //  n(r-2)   , n(r-1)
        int prev_rock_step=1, curr_rock_step=1;
        while(step_position<=ROCKS){
            int temp = prev_rock_step;
            prev_rock_step = curr_rock_step;
            curr_rock_step = temp + curr_rock_step;

            step_position += 1;
        }
        return curr_rock_step;
    }
};

int main(){{
     RiverCrossing obj1(5);
     cout<<obj1.get_no_of_ways()<<"\n";
}