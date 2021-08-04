#include<stdio.h>
#include<stdlib.h>
int fibo(int k)
{
	if(k<=1) return k;
	return fibo(k-1) + fibo(k-2);
}
int main()
{
	int k;
	printf("Enter Number : ");
	scanf("%d", &k);
	printf("%d", fibo(k));
	return 0;
}