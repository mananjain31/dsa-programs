#include<stdio.h>
int main()
{
	int s,b,r,gcd;
	printf("Enter a No. : ");
	scanf("%d", &s);
	printf("Enter a No. : ");
	scanf("%d", &b);

	if(s>b){
		s = s+b;
		b = s-b;
		s = s-b;
	}

	r = b%s;
	while(r){
		b = s;
		s = r;
		r = b%s;
	}	
	gcd = s;

	printf("Gcd : %d", gcd);
	return 0;
}