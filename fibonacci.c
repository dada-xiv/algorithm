/* 
 * 03. Functions
 * Fibonacci sequence generator
 */

#include <stdio.h>

void printFibonacci(int n){
    int a=0, b=1;
    int c;
    char res;

    if(n==1){
        printf("%d", a);
    }else if(n==2){
        printf("%d, %d", a, b);
    }else{
    printf("%d, %d", a, b);
        for(int i=2;i<n;i++){
            c = a + b;
            a = b;
            b = c;
            printf(", %d",c);
        }
    }
}

int main(void){
    int num;

    printf("Input number: ");
    scanf("%d", &num);

    printFibonacci(num);

    printf("\n");
    return 0;
}