#include<stdio.h>
void showLoop(int a[], int n)
{
	int i;
	for(i=(n/2)-1; i>=0;i--)
		show(a,i,n);
}
void main()
{
	int i, a[]={1,2,3,4,5,6,7};
	show(a,7);
}