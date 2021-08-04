#include<stdio.h>
#include<stdlib.h>
int *dp;
int fibo(int k)
{
	if(k<=1) return k;
	if(dp[k]) return dp[k];
	dp[k] = fibo(k-1) + fibo(k-2); 
	return dp[k];
}
int main()
{
	int k;
	printf("Enter Number : ");
	scanf("%d", &k);
	dp = (int*)malloc(sizeof(int)*(k+1));
	for(int i=0;i<=k;i++)dp[i] = 0;
	printf("%d", fibo(k));
	return 0;
}