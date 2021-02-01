#include<stdio.h>
void countingSort(int x[], int n)
{
	int i,max = x[0];
	for(i = 0; i<n; i++)
	{
		if(x[i] > max)
			max = x[i];
	}
	max++;
	int a[max];
	for(i = 0; i<max; i++)
		a[i] = 0;
	
	for(i = 0; i<n; i++)
		a[x[i]]++;
	
	for(i = 1; i<max; i++)
		a[i] += a[i-1];
	
	int y[n];
	for(i = 0; i<n; i++)
		y[ a[x[i]]-1 ] = x[i];
	for(i=0;i<n;i++)
		printf("%d ",y[i]);
	
	
}
void main()
{
	int x[] = {8,7,6,4,1,9,12,-1};
	int n = sizeof(x)/sizeof(x[0]);
	countingSort(x,n);
}