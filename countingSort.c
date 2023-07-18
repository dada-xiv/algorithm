/*
 * Counting sort
 */

#include <stdio.h>

void countingSort(int a[], int n) {
    // Creates a list of size max number in the array
    int max = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max) max = a[i];
    }

    int crr[max + 1];

    // Initialize count array with all zeros
    for(int i=0;i<=max;i++){
        crr[i] = 0;
    }

    // Store the count of each element
    for(int i=0;i<n;i++){
        crr[a[i]]++;
    }

    // Store the cumulative count of each array
    for(int i=1;i<=max;i++){
        crr[i] += crr[i-1];
    }

    // Sorting phase: Find the index of each element of the original array in count array, and place the elements in output array
    int result[n];
    for(int i=0;i<n;i++) {
        result[crr[a[i]]-1] = a[i];
        crr[a[i]]--;
    }

    // Copy the sorted elements into original array
    for(int i=0;i<n;i++){
        a[i] = result[i];
    }
}

int main() {
    int n;
    int a[] = {3, 1, 2, 5, 4, 6};
    int b[] = {5, 5, 3, 3, 1, 1};
    int c[] = {10, 8, 2, 3, 1, 2, 8, 4, 12, 3, 5, 11, 7, 5};

    n = sizeof(a)/sizeof(a[0]);
    countingSort(a, n);
    for (int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");

    n = sizeof(b)/sizeof(b[0]);
    countingSort(b, n);
    for (int i=0;i<n;i++) printf("%d ", b[i]);
    printf("\n");

    n = sizeof(c)/sizeof(c[0]);
    countingSort(c, n);
    for (int i=0;i<n;i++) printf("%d ", c[i]);
    printf("\n");

    return 0;
}
