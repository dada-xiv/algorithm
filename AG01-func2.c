/*
 * Given an integer array `arr[]` of length `N`, if there exist 
 * two elements at different positions such that their sum is 
 * equal to 100, return 1; otherwise, return 0. 
 * Each element of `arr` is an integer ranging from 0 to 100, 
 * and the value of `N` is at most 1000:
 */

#include <stdio.h>

int func2(int a[], int N){
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(a[i] + a[j] == 100) return 1;
        }
    }
    return 0;
}


int main(){
    int arr1[3] = {1, 52, 48};
    printf("%d\n", func2(arr1, 3));

    int arr2[2] = {50, 42};
    printf("%d\n", func2(arr2, 2));

    int arr3[4] = {4, 13, 63, 87};
    printf("%d\n", func2(arr3, 4));  

    return 0;
}