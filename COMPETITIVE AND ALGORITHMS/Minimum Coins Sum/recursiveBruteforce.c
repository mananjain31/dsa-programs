#include<stdio.h>
long copiesCount = 0;
void getMinCoins(int *x, int n, int numberOfCoins, int sum,int* min) 
{
	if(numberOfCoins > *min) return;
	if(sum < 0) return;
	copiesCount++;
	if(sum == 0)
	{
		if(numberOfCoins < *min) *min = numberOfCoins;
		return;
	}
	for(int i=0;i<n;i++)
	{
		getMinCoins(x,n,numberOfCoins+1,sum-x[i],min);
	}
}
int getMinimumCoins(int *x, int n, int sum)
{
	int min=2147483647;
	int* minPtr = &min;
	getMinCoins(x,n,0,sum,minPtr);
	return min;
}
int main()
{
	int coins[] = {2, 5, 10};
	int n = sizeof(coins)/sizeof(coins[0]);
	int sum = 100;
	printf("minimum  no of coins required to get sum %d is : %d\n",sum,getMinimumCoins(coins, n, sum));
	printf("Copies created : %d\n", copiesCount);
}