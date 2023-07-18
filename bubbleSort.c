/*
 * Bubble sort
 */

#include <stdio.h>

void bubbleSort(int *a, int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    int a[] = {5, 6, 4, 7, 3, 1, 8, 2, 9, 0};
    n = sizeof(a)/sizeof(a[0]);

    bubbleSort(a, n);
    
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }

    return 0;
}
