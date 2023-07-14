/* 
 *  Factorial function n!
 */

#include <stdio.h>

int main(void){
    int n;
    int res = 1;

    printf("Input n : ");
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        res *= i;
    }

    printf("%d! = %d\n", n, res);

    return 0;
}