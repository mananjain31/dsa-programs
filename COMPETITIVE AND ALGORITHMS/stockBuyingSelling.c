#include<stdio.h>
int getMaxProfit(int* x, int n)
{
	int maxProfit = 0;
	int min = x[0];
	int i, j;
	for(i=1;i<n;i++)
	{
		if(x[i] < min) min = x[i];
		else
		{
			j = x[i] - min;
			if(j > maxProfit) maxProfit = j;
		}
	}
	return maxProfit;
}
int main()
{
	int x[] = {5, 30, 2, 20};
	// int x[] = {5,5,5,5,5};
	printf("%d\n", getMaxProfit(x, sizeof(x)/sizeof(x[0])));
	return 0;
}