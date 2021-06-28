// https://www.youtube.com/watch?v=Afnthubp_-M&t=2229s
/*
Implement a function willFirstPlaterWin that takes input as a number and returns whether the 
first player will win the game as per below rules:
- In each turn, you can decrease the current number from 1 to 9.
- The player who makes the current number 0 wins the game.
- Each player plays optimally

Example:
If curNumber = 23,
A subtracts 9 => curNumber = 23 - 9 = 14 
B subtracts 7 => curNumber = 14 - 7 = 7 
A subtracts 7 and makes 0, so A wins. 
*/
#include<bits/stdc++.h>
using namespace std;

bool willFirstPlayerWin(int num){
    if(num%10 == 0)
        return false;
    return true;
}

int main(){
    cout<<willFirstPlayerWin(23)<<"\n";
}