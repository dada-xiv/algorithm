/*
 * Merge sort, without global sorted[]
 */

#include <stdio.h>

void merge(int a[], int left, int mid, int right){
    int pivotL = left;
    int pivotR = mid + 1;
    int k = left;
    int n = right-left+1;
    int sorted[n];
    //for(int i=0;i<n;i++) sorted[i] = 0;

    while(pivotL<=mid && pivotR<=right){
        if(a[pivotL] <= a[pivotR]){
            sorted[k-left] = a[pivotL];
            k++;
            pivotL++;
        }else{
            sorted[k-left] = a[pivotR];
            k++;
            pivotR++;
        }
    }

    // Copy the remaining elements
    while(pivotL <= mid){
        sorted[k-left] = a[pivotL];
        k++;
        pivotL++;
    }

    while(pivotR <= right){
        sorted[k-left] = a[pivotR];
        k++;
        pivotR++;
    }

    // Copy the sorted result into the array
    for(int i=left;i<=right;i++){
        a[i] = sorted[i-left];
    }
}

void mergeSort(int a[], int left, int right){
    int mid;

    if(left < right){
        mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        merge(a, left, mid, right);        
    }
}

int main(){
    int a[] = {23, 8, 15, 19, 11, 27, 10, 12, 21};
    int n;
    n = sizeof(a)/sizeof(a[0]);

    mergeSort(a, 0, n-1);

    for(int i;i<n;i++){
        printf("%d ", a[i]);
    }

    return 0;
}
