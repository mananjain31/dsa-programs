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
	int i,a[]={4,0,2,3,7,1,8,5,9,6};
	int n = sizeof(a)/sizeof(a[0]);
	display(a,n);
}