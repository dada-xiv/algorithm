/* 
 * Length of the digits in a given natural number
 * 
 */

#include <stdio.h>
#include <math.h>

int main() {
    int number = 245;
    int length = (int) log10(number) + 1;

    printf("Length of digits: %d\n", length);

    return 0;
}
