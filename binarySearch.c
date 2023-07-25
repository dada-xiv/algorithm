/*
 * Binary search
 */

#include <stdio.h>

int binarySearch(int a[], int L, int R, int target){
    int m;
    while(L <= R){
        m = (L+R)/2;
        if(a[m] == target){
            return m;
        }else if(a[m] > target){
            R = m-1;
        }else{
            L = m+1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 4, 5, 7, 9, 10, 11, 12, 13, 13, 13, 17, 19, 20};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", binarySearch(arr, 0, len-1, 12));

    // If duplicate elements are present, it returns one of the indices.
    printf("%d\n", binarySearch(arr, 0, len-1, 13));

    printf("%d\n", binarySearch(arr, 0, len-1, 15));
    
    return 0;
}