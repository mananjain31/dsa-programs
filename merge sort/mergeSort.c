#include<stdio.h>
void split();
void merge();
void display(int[],int);
void main()
{
	int n,i;
	printf("Enter No. of elements to perform Merge sort: ");
	scanf("%d", &n);
	int x[n];
	for(i = 0; i<n; i++)
	{
		printf("Enter %d numbered value: ",i+1);
		scanf("%d",&x[i]);
	}
	printf("Sorted Array is : \n");
	display(x,n);
}
void display(int x[], int n)
{
	int i;
	for(i=0;i<n;i++)printf("%d ", x[i]);
}