// https://www.youtube.com/watch?v=mDYOy7k8kOQ
#include<bits/stdc++.h>
using namespace std;

class Replacer{
    // instance variable
    int NUM;
public:
    Replacer(int num){
        NUM=num;
    }

    int replace_method(){
        int num=NUM;
        int result_num =0;

        int position =0;
        while(num){
            int lsd = num%10;
            num /= 10;

            if(lsd==0){
                result_num += pow(10, position)*5;
            }else{
                result_num += pow(10, position)*lsd;
            }
            position += 1; 
        }
        return result_num;
    }

};

int main(){
  Replacer obj1(102);
  cout<<obj1.replace_method()<<"\n";

  Replacer obj2(1020);
  cout<<obj2.replace_method()<<"\n";
    
}