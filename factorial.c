/* 
 *  Factorial n!
 */

#include <stdio.h>

int factorial(int n){
    int res = 1;
    for(int k=1;k<=n;k++){
        res *= k;
    }
    return res;
}

int main(void){
    printf("3! = %d\n", factorial(3));
    printf("4! = %d\n", factorial(4));
    printf("9! = %d\n", factorial(9));
    return 0;
}