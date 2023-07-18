/*
 * Counting sort (without cumulative sums)
 */

#include <stdio.h>

void countingSort(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    int crr[max + 1];
    for (int i = 0; i <= max; i++) {
        crr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        crr[a[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (crr[i] > 0) {
            a[index++] = i;
            crr[i]--;
        }
    }
}

int main() {
    int n;
    int a[] = {3, 1, 2, 5, 4, 6};
    int b[] = {6, 5, 4, 3, 2, 1};
    int c[] = {5, 5, 3, 3, 1, 1};

    n = sizeof(a) / sizeof(a[0]);
    countingSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    n = sizeof(b) / sizeof(b[0]);
    countingSort(b, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    n = sizeof(c) / sizeof(c[0]);
    countingSort(c, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
