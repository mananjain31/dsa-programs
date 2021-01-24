#include<stdio.h>
void display(int x[], int n);
void main()
{
	int n,i,j;
	printf("__SELECTION SORT__\n");
	printf("Enter size of array: ");
	scanf("%d",&n);
	int x[n];
	for(i=0;i<n;i++)
	{
		printf("Enter %d numbered array value: ", i+1);
		scanf("%d",&x[i]);
	}
	int min;
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(x[min] > x[j]) 
				min = j;
		}
		if(min!=i)
		{
			int t = x[min];
			x[min] = x[i];
			x[i] = t;
		}
	}
	display(x,n);
}
void display(int x[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d  ",x[i]);
	}
}