#include <stdio.h>

int func4(int N){
    int power = 1;
    while(power*2 <= N){
        power *= 2;
    }
    return power;
}


int main(){
    printf("%d\n", func4(5));
    printf("%d\n", func4(97615282));
    printf("%d\n", func4(1024));

    return 0;
}