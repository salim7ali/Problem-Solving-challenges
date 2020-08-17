// https://www.youtube.com/watch?v=hGK_5n81drs
// #include <bits/stdc++.h>
// used video as reference to solve the problem
// solved by modifying the quickSort algorithm
#include <vector>
#include <iostream>
using namespace std;

int partition(int* numbers, int Left, int Right){
    int i=Left-1; 
    for(int j=Left; j<=Right-1; j++){
        if(numbers[j]<numbers[Right]){
            i += 1;
            swap(numbers[i], numbers[j]);
        }
    }
    swap(numbers[i+1], numbers[Right]);
    return i+1;
}
int modQuickSort(int* numbers, int Left, int Right, int k){
    if(Left<=Right){
        int parti = partition(numbers, Left, Right);
        if(k==parti)
            return numbers[k];
        else if(k<parti)
            modQuickSort(numbers, Left, parti-1, k);
        else
            modQuickSort(numbers, parti+1, Right, k);
    }
}

int main(){
    int numbers[] = {3, 2, 1, 5, 6, 4};
    int size = *(&numbers+1)-numbers;
    int k =4;
    cout<<modQuickSort(numbers, 0, size-1, k-1);
}
