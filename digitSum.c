/*
 * Calculate the sum of the individual digits in a given number
 */

#include <stdio.h>

int calculateDigitSum(int number) {
    int sum = 0;

    while (number > 0) {
        sum += number % 10; // Extract the last digit and add it to the sum
        number /= 10; // Remove the last digit
    }

    return sum;
}

int main() {
    int number = 245;
    int digitSum = calculateDigitSum(number);

    printf("Sum of digits: %d\n", digitSum);

    return 0;
}