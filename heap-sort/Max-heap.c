#include<stdio.h>
void display(int a[], int n);
void show(int a[], int i, int n)
{
	int t,l = i*2 + 1, r = i*2 + 2;
	if(r<n)
		l = (a[l]>a[r])?l:r;
	if(l<n && a[i]<a[l])
	{
		t=a[i];
		a[i] = a[l];
		a[l] = t;
		display(a,n);
		show(a,l,n);
	}
}
void showLoop(int a[], int n)
{
	int i;
	for(i=(n/2)-1; i>=0;i--)
		show(a,i,n);
}
void main()
{
	int i, a[]={1,2,3,4,5,6};
	int n = sizeof(a)/sizeof(a[0]);
	showLoop(a,n);
	display(a,n);
}
void display(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}