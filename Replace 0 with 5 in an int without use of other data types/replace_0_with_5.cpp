// https://www.youtube.com/watch?v=mDYOy7k8kOQ
#include<bits/stdc++.h>
using namespace std;

class Replacer{
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
    }

};

int main(){
  Replacer obj(102);
  obj.replace_method();
    
}