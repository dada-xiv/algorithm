#include <stdio.h>

int getMax(int a, int b, int c){
    if(a>b)
        return (a>c) ? a : c;
    else
        return (b>c) ? b : c;
}

int getMin(int a, int b, int c){
    if(a<b)
        return (a<c) ? a : c;
    else
        return (b<c) ? b : c;
}

int main(void){
    int a, b, c;
    int min, max;

    printf("Input three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    max = getMax(a, b, c);
    min = getMin(a, b, c);

    printf("Min = %d, Max = %d", min, max);

    return 0;
}