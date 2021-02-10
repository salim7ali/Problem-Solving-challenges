// Find Excel column name from a given column number
#include<bits/stdc++.h>
using namespace std;

string excelColName(int num){
    const int TS = 26;
    stack<int> resultNums;

    int rem=0, quot=0;
    while(1){
       quot = floor(num/TS);
       cout<<quot;
       rem = num%TS;
       cout<<rem;
       resultNums.push(rem);
       if(quot ==1){
           resultNums.push(quot);
           break;
       }
       num = quot;
    } 

    string result;
    while(resultNums.empty()==false){
        // cout<<resultNums.top()<<" ";
        int num = resultNums.top();
        result.push_back((char)65+num-1);
        resultNums.pop();
    }
    return result;
}
int main(){
    // cout<<excelColName(26)<<"\n";
    cout<<excelColName(51)<<"\n";
    // cout<<excelColName(52)<<"\n";
    // cout<<excelColName(80)<<"\n";
//     cout<<excelColName(676)<<"\n";
//     cout<<excelColName(702)<<"\n";
//     cout<<excelColName(705)<<"\n";
}
