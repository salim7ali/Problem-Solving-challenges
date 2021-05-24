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

    int replace_zero(){
        if(NUM==0)
            return 5;
        
        int num=abs(NUM);
        int result_num =0;


        int position =0;
        while(num){
            int lsd = num%10;
            num /= 10;

            if(lsd==0)
                result_num += pow(10, position)*5;
            else
                result_num += pow(10, position)*lsd;
            position += 1; 
        }
        if(NUM<0)
            result_num *= -1;

        return result_num;
    }
};

int main(){
  Replacer obj1(102);
  cout<<obj1.replace_zero()<<"\n";

  Replacer obj2(1020);
  cout<<obj2.replace_zero()<<"\n";

  Replacer obj3(-503210);
  cout<<obj3.replace_zero()<<"\n";

  Replacer obj4(0);
  cout<<obj4.replace_zero()<<"\n";

  Replacer obj5(-1);
  cout<<obj5.replace_zero()<<"\n";
    
}