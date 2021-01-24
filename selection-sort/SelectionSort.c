#include<stdio.h>
void display(int x[], int n);
void main()
{
	int n,i;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int x[n];
	for(i=0;i<n;i++)
	{
		printf("Enter %d numbered array value: ", i+1);
		scanf("%d",&x[i]);
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
