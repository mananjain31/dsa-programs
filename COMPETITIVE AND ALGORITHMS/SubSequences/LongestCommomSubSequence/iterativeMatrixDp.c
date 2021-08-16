#include<stdio.h>
int main()
{
	int x[6] = {65, 66, 67, 68, 80, 90};
	int y[4] = {66, 90, 68, 90};
	int lenx = 6;
	int leny = 4;
	int dp[lenx+1][leny+1];
	int e,f;

	for(e=0;e<=lenx;e++)dp[e][0] = 0;
	for(e=0;e<=leny;e++)dp[0][e] = 0;

	int max = 0, maxe, maxf;
	for(e=1;e<=lenx;e++)
	{
		for(f=1;f<=leny;f++)
		{
			if(x[e-1] == y[f-1]) dp[e][f] = dp[e-1][f-1] + 1;
			else dp[e][f] = dp[e-1][f] > dp[e][f-1] ? dp[e-1][f] : dp[e][f-1];
			if(dp[e][f] > max)
			{ 
				max = dp[e][f];
				maxe = e;
				maxf = f;
			}
		}
	}

	for(e=0;e<=lenx;e++)
	{
		for(f=0;f<=leny;f++) printf("%d ",dp[e][f]);
		printf("\n");
	}

	printf("LCS in reverse order : ");
	e = maxe, f=maxf;
	while(e!=0 && f!=0)
	{
		if (dp[e-1][f] == dp[e][f]) e--;
		else if(dp[e-1][f] == dp[e][f]) f--;
		else
		{
			printf("%d ", x[e-1]);
			e--;
			f--;
		}
	}
	printf("\n");

	printf("Length of longest common substring : %d\n", max);
}