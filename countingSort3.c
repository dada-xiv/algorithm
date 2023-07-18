/*
 * Counting sort : when the limit of maximum number is given
 */

#include <stdio.h>

#define SIZE 10000 // The limit of maximum number

void countingSort_simple(int a[], int n){
    int crr[SIZE+1] = {0};

    for(int i=0;i<n;i++){
        crr[a[i]] += 1;
    }

    int result[n];
    int idx = 0;
    for(int i=1;i<=SIZE;i++){
        if(crr[i]==0) continue;
        for(int j=0;j<crr[i];j++){
            result[idx] = i;
            idx++;
        }
    }

    for(int i=0;i<n;i++){
        a[i] = result[i];
    }
}

int main() {    
    int c[] = {10, 8, 2, 3, 1, 2, 8, 4, 12, 3, 5, 11, 7, 5};

    int n = sizeof(c)/sizeof(c[0]);
    countingSort_simple(c, n);
    for (int i=0;i<n;i++) printf("%d ", c[i]);
    printf("\n");

    return 0;
}