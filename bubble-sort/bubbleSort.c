#include<stdio.h>
void display(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void bubbleSort(int a[], int n)
{
	int i,j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n-1-i; j++)
		{
			if(a[j] > a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
			display(a,n);
		}
			printf("\n");
	}
}
void main()
{
	int a[]={6,5,3,1,9,7,2,4,1};
	int n =sizeof(a)/sizeof(a[0]);
	printf("some output for understanding:\n");
	bubbleSort(a,n);
	printf("\nsorted array:\n");
	display(a,n);
}