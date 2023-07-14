/* 
 *  Euclidean algorithm
 *
 */
#include <stdio.h>

int main(void){
	int m, n, r;
	int nGCD;
	
	printf("Enter two numbers : ");
	scanf("%d %d",&m,&n);
	
	while(n!=0){
		r = m%n;
		m = n;
		n = r;
	}
	nGCD = m;
	
	printf("Greatest common divisor : %d\n",nGCD);
	
	return 0;	
}