#include<bits/stdc++.h>
using namespace std;

int yearValue(int year){
    if(year>=1600 && year<=1699)
        return 6;
    else if(year>=1700 && year<=1799)
        return 4;
    else if(year>=1800 && year<=1899)
        return 2;
    else if(year>=1900 && year<=1999)
        return 0;
    else //(year>=2000 && year<=2099)
        return 6;
}

int FindDayOfWeek(int day, int month, int year){
    vector<int> monthDigit = {0, 3, 3, 6, 1, 4, 6,2 , 5, 0,3,5}; 
    
    int sumOfResult = 0;

    int yearLastTwoDigits = year%100;
    sumOfResult += yearLastTwoDigits;
    
    int quotient = yearLastTwoDigits/4;
    sumOfResult += quotient;

    sumOfResult += day;

    sumOfResult += monthDigit[month-1];

    sumOfResult += yearValue(year);
    
    int result = sumOfResult%7;

    if(year%4==0 && (month==1 ||  month==2))
        result -= 1;
-
    return result;
}

int main(){
    cout<<FindDayOfWeek(8, 7, 2015)<<"\n";
    cout<<FindDayOfWeek(26, 7, 1990)<<"\n";
}