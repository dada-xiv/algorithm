/*
 * Selection sort
 * 
 */

#include <stdio.h>
#define SIZE 9
int sorted[SIZE]; // Global array for sorted result

void merge(int a[], int left, int mid, int right){
    int pivotL = left;
    int pivotR = mid + 1;
    int k = left;

    while(pivotL<=mid && pivotR<=right){
        if(a[pivotL] <= a[pivotR]){
            sorted[k++] = a[pivotL++];
        }else{
            sorted[k++] = a[pivotR++];
        }
    }

    // Copy the remaining elements
    if(pivotL<=mid){
        for(int i=pivotL;i<=mid;i++){
            sorted[k++] = a[i];
        }
    }else if(pivotR<=right){
        for(int i=pivotR;i<=right;i++){
            sorted[k++] = a[i];
        }
    }

    // Copy the sorted result into the array
    for(int i=left;i<=right;i++){
        a[i] = sorted[i];
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
    int N = SIZE;
    int a[] = {23, 8, 15, 19, 11, 27, 10, 12, 21};

    mergeSort(a, 0, N-1);

    for(int i;i<N;i++){
        printf("%d ", a[i]);
    }

    return 0;
}
