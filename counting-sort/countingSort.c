#include<stdio.h>
void countingSort(int x[], int n)
{
	int i,min = x[0],max = x[0];
	for(i = 1; i<n; i++)
	{
		if(x[i] > max)
			max = x[i];
		if(min>x[i])
			min = x[i];
	}

	max++;
	
	int a[max-min];
	for(i=0; i<n; i++)
		x[i] = x[i]-min;
	
	for(i = 0; i<max-min; i++)
		a[i] = 0;
	
	for(i = 0; i<n; i++)
		a[x[i]]++;
	
	for(i = 1; i<max-min; i++)
		a[i] += a[i-1];
	
	int y[n];
	for(i = 0; i<n; i++)
	{
		y[a[x[i]]-=1] = x[i];
	}
	for(i=0;i<n;i++)
		x[i] = y[i] + min;
	
}
void main()
{
	int i;
	int x[] = {8,7,6,4,1,-9,1,20,2,-3,3};
	int n = sizeof(x)/sizeof(x[0]);
	countingSort(x,n);
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
}