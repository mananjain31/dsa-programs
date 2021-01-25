#include<stdio.h>
void display(int x[], int n)
{
	for(int i=0;i<n;i++) 
		printf("%d ",x[i]);
}
void main()
{
	int n;
	printf("Enter Size of array: ");
	scanf("%d",&n);
	int x[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter %d numbered value: ",i+1);
		scanf("%d",&x[i]);
	}
	display(x, n);
}