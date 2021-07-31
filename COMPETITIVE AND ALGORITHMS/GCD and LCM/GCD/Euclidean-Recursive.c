#include<stdio.h>
int _gcd(int s, int b){
	if(b%s) return _gcd(b%s,s);
	return s;
}
int gcd(int s, int b){
	if(s>b) return _gcd(b,s);
	return _gcd(s,b);
}
int main()
{
	int s,b,r;
	printf("Enter a No. : ");
	scanf("%d", &s);
	printf("Enter a No. : ");
	scanf("%d", &b);

	printf("Gcd : %d", gcd(s,b));
	return 0;
}