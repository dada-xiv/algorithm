#include <stdio.h>

int main(void){
    int a, b, c;
    int min, max;

    printf("Input three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a>b){
        if(a>c){
            max = a;
            if(b>c){
                min = c;
            }else{
                min = b;
            }
        }else{
            max = c;
            min = b;
        } 
    }else{
        if(b>c){
            max = b;
            if(c>a){
                min = a;
            }else{
                min = c;
            }
        }else{
            max = c;
            min = a;
        }
    }

    printf("Min = %d, Max = %d", min, max);

    return 0;
}