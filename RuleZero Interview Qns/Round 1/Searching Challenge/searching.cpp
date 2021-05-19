#include<bits/stdc++.h>
using namespace std;

class Searching{
    // instance variable
    string str;
public:
    Searching(string str){
        this->str = str;
    }
    string SearchingChallenge(){
        stack<char> St;

        for(int i=0; i<this->str.length(); i++){
            if(this->str[i] == '(')
                St.push('(');
            if(this->str[i] == ')'){
                if(St.empty()==false)
                    St.pop();
                else 
                    return "0"; 
            }
        }

        if(St.empty() == true)
            return "1";
        return "0";
    }
}; 

int main(){
    Searching obj1("(coder)(byte))");
    cout<<obj1.SearchingChallenge()<<"\n";

    Searching obj2("(c(oder))b(yte)");
    cout<<obj2.SearchingChallenge()<<"\n";
}