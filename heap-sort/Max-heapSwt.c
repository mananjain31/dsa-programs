#include<stdio.h>
void display(int a[], int n);
void show(int x[],int i, int n)
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int t;
	int max = i;
	if(l<n && x[l] > x[r])
	{
		max = l;
	}
	if(r<n && x[r] > x[l])
	{
		max = r;
	}
	
	if(x[i] < x[max])
	{
		t = x[i];
		x[i] = x[max];
		x[max] = t;
		show(x, max, n);
	}
}
void showLoop(int x[], int n)
{
	int i;
	for(i = (n/2)-1; i>=0; i--)
	{
		show(x,i,n);
	}
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