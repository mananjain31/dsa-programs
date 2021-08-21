#include<stdio.h>
#include<limits.h>
int getMinimumCoins(int *x, int n, int sum)
{
	int i,j,num;
	int dp[n+1][sum+1];
	for(i=0;i<=sum;i++)dp[0][i] = INT_MAX;
	for(i=0;i<=n;i++)dp[i][0] = 0;

	for(i=1;i<=n;i++)
	{
		num = x[i-1];
		for(j=1;j<=sum;j++)
		{
			if(j<num)
			{
				dp[i][j] = dp[i-1][j];
			}
			else if(dp[i][j-num] == INT_MAX)
			{
				dp[i][j] = dp[i-1][j];
			}
			else if(dp[i][j-num]+1 < dp[i-1][j])
			{
				dp[i][j] = dp[i][j-num]+1;
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	i=n,j=sum;
	while(i>0 && j>0)
	{
		if(dp[i][j] == dp[i-1][j])
		{
			i--;
		}
		else
		{ 
			j-=x[i-1];
			printf("%d ", x[i-1]);
		}
	}
	printf("\n");

	// for(i=0;i<=n;i++)
	// {
	// 	for(j=0;j<=sum;j++)printf("%d ", dp[i][j]);
	// 	printf("\n");
	// }
	return dp[n][sum];
}
int main()
{
	int coins[] = {2, 3, 5};
	int n = sizeof(coins)/sizeof(coins[0]);
	int sum = 21;
	printf("minimum  no of coins required to get sum %d is : %d\n",sum,getMinimumCoins(coins, n, sum));
}