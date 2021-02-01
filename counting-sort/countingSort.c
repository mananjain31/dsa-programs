#include<stdio.h>
void countingSort(int x[], int n)
{
	int i,max = x[0];
	for(i = 1; i<n; i++)
		if(max<x[i]) 
			max = x[i]; 
	
	int a[max];
	for(i=0;i<max;i++)
		a[i] = 0;
	
	for(i = 0; i<n; i++)
		a[x[i]]++;
	
	for(i = 0; i<max; i++)
		printf("%d ",a[i]);
	printf("\n");
}
void main()
{
	int x[] = {8,7,6,4,1,9};
	countingSort(x,sizeof(x)/sizeof(x[0]));
}