#include<stdio.h>
int main()
{
	int a,b,gcd,i;
	printf("Enter a No. : ");
	scanf("%d", &a);
	printf("Enter a No. : ");
	scanf("%d", &b);

	if(a>b){
		a = a+b;
		b = a-b;
		a = a-b;
	}
	if(b%a == 0){
		gcd = a;
	} 
	else{
		 i = a/2;
		while(!(b%i==0 && a%i==0)){
			i--;
		}
		gcd = i;
	}

	printf("Gcd : %d", gcd);
	return 0;
}