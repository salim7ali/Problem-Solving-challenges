// https://www.youtube.com/watch?v=qEJcAuH7rZg&t=820s
// series: 1, 1, 2, 3, 4, 9, 8, 27, 16, 81, 32, 243, 64, 729, 128, 2187,....

// #include<bits/stdc++.h>


#include<iostream>

class Series{
    int curr=1, next=1;
    public:
    void generateSeries(int size){
        for(int i=0; i<size; i++){
            std::cout<<curr<<", "<<next<<", ";
            curr *=2;
            next *=3;
        }
    };

};

int main(){
    Series object;

    int size = 7;
    object.generateSeries(size);
}
