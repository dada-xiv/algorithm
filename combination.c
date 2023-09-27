/*
 * Combination (n, r): get r combinations among n elements
 *
 */

#include <stdio.h>

int main(void) {
  int n = 6;
  int r = 3;
  // int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (int i = 1; i <= n - 2; i++) {
    for (int j = i + 1; j <= n - 1; j++) {
      for (int k = j + 1; k <= n; k++) {
        // printf("%d %d %d\n", a[i], a[j], a[k]);
        printf("%d %d %d\n", i, j, k);
      }
    }
  }

  return 0;
}