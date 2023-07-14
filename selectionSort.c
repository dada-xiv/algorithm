/*
This ``brute force'' method is one of the simplest sorting algorithms.
Approach:

Find the smallest element in the array and exchange it with the element in the first position.
Find the second smallest element in the array and exchange it with the element in the second position.
Continue this process until done.

Selection sort is easy to implement; there is little that can go wrong with it. However, the method requires O(N^2) comparisons and so it should only be used on small files. 

There is an important exception to this rule. When sorting files with large records and small keys, the cost of exchanging records controls the running time. In such cases, selection sort requires O(N) time since the number of exchanges is at most N.

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
