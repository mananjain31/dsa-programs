#include<stdio.h>
#include<stdlib.h>
int solve(int *a, int lb, int ub)
{
	int i,j;
	int max = 1;
	int *b = (int*)malloc(sizeof(int)*(ub-lb+1));
	for(i=lb;i<=ub;i++) b[i] = 1;
	i=lb;
	j=lb+1;
	while(j<=ub)
	{
		i = lb;
		while(i<j)
		{
			if(a[j]>=a[i])
			{
				if(b[j] < b[i]+1)
				{
					b[j] = b[i]+1;
					if(b[j] > max) max = b[j];
				}
			}	
			i++;
		}
		j++;
	}
	return max;
}
int main()
{
	// int a[] = {12, 3, 92, -3, 76, 54, 12, 93, 78};
	int a[] = {1,2,3,4,90,21,3,5,6,7,9,10,100};
	/*
	int n,i;
	int *a;
	printf("Enter number of elements : ");
	a = (int*)malloc(sizeof(int)*n);
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("Enter a Number ");
		scanf("%d", a+i);
	}
	*/
	printf("Longest Increasing Subsequence Length : %d", solve(a,0,sizeof(a)/sizeof(a[0])));

	return 0;
}