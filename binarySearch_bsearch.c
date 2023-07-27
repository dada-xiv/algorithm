/*
 * Binary search
 */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *key, const void *element){
    int nkey = *(int *)key;
    int nElement = *(int *)element;
    if(nkey > nElement) return 1;
    else if(nkey < nElement) return -1;
    else return 0;
}

int main() {
    int arr[] = {1, 3, 4, 5, 7, 9, 10, 11, 12, 13, 13, 13, 17, 19, 20};
    int len = sizeof(arr) / sizeof(arr[0]);
    int *p;
    int key;

    key = 12;
    p = (int *)bsearch(&key, arr, len, sizeof(int), compare);
    if (p != NULL) {
        printf("%d\n", (int)(p - arr));
    } else {
        printf("Key not found.\n");
    }

    // If duplicate elements are present, it returns one of the indices.
    key = 13;
    p = (int *)bsearch(&key, arr, len, sizeof(int), compare);
    if (p != NULL) {
        printf("%d\n", (int)(p - arr));
    } else {
        printf("Key not found.\n");
    }

    key = 15;
    p = (int *)bsearch(&key, arr, len, sizeof(int), compare);
    if (p != NULL) {
        printf("%d\n", (int)(p - arr));
    } else {
        printf("Key not found.\n");
    }
    
    return 0;
}