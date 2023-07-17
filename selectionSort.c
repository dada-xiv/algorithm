/*
 * Selection sort
 * 
 */

#include <stdio.h>

void selectionSort(int *a, int N){
    int min;
    for(int i=0;i<N-1;i++){
        min = a[i];
        for(int j=i+1;j<N;j++){
            if(a[j] < min){
                a[i] = a[j];
                a[j] = min;
                min = a[i]; // New a[i] is the smallest
            }
        }
    }
}

int main(){
    int N = 10;
    int a[] = {5, 6, 4, 7, 3, 1, 8, 2, 9, 0};

    selectionSort(a, N);
    
    // Print the result
    for(int k=0;k<N;k++){
        printf("%d ", a[k]);
    } 

    return 0;
}
