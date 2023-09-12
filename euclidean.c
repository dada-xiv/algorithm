#include <stdio.h>

int getGCD(int m, int n) {
  while (n != 0) {
    int r = m % n;
    m = n;
    n = r;
  }
  return m;
}

int main() {
  printf("%d\n", getGCD(40, 232));
  return 0;
}