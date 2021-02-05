#include<stdio.h>
void display(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void main()
{
	int a[]={6,5,3,1,9,7,2,4,1};
	int n =sizeof(a)/sizeof(a[0]);
	display(a,n);
}