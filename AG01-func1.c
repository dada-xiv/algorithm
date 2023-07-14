/*
 * Given a positive integer N, returns the sum of all positive integers 
 * that are less than or equal to N and are multiples of either 3 or 5.
 */

#include <stdio.h>

int func1(int N){
    int sum = 0;
    for(int i=1;i<=N;i++){
        if(i%3==0 || i%5==0){
            sum += i;
        }
    }
    return sum;
}

int func1mod(int N) {
    int sum = 0;

    int numMultiples3 = N / 3;  // Number of multiples of 3
    int sumMultiples3 = (numMultiples3 * (numMultiples3 + 1)) / 2;

    int numMultiples5 = N / 5;  // Number of multiples of 5
    int sumMultiples5 = (numMultiples5 * (numMultiples5 + 1)) / 2;

    int numMultiples15 = N / 15;  // Number of multiples of both 3 and 5
    int sumMultiples15 = (numMultiples15 * (numMultiples15 + 1)) / 2;

    // Calculate the total sum
    sum = (3 * sumMultiples3) + (5 * sumMultiples5) - (15 * sumMultiples15);

    return sum;
}


int main(){
    printf("%d\n", func1(16));
    printf("%d\n", func1(34567));
    printf("%d\n", func1(27639));
    printf("%d\n", func1mod(16));
    printf("%d\n", func1mod(34567));
    printf("%d\n", func1mod(27639));
}