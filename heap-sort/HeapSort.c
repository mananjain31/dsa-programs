#include<stdio.h>
show(int x[], int i, int n)
{
	int max = i;
	int t;
	int l = i*2 + 1;
	int r = i*2 + 2;
	
	if(l<n && x[l] > x[max] )
	{
		max = l;
	}
	
	if(r<n && x[r] > x[max])
	{
		max = r;
	}
	
	if(x[i] < x[max])
	{
		t = x[i];
		x[i] = x[max];
		x[max] = t;
		show(x,max,n);
	}
	
}
void showloop(int x[], int n)
{
	int i;
	for(i = (n/2)-1 ; i>=0 ;i--)
	{
		show(x,i,n);
	}
}
void deletedemo(int x[], int n)
{
	int i;
	for(i = n-1; i>0; i--)
	{
		int t = x[0];
		x[0] = x[i];
		x[i] = t;
		show(x,0,i);
	}
}
void insertdemo(int x[],int a, int n)
{
	int i;
	x[n] = a;
	for(i = (n-1)/2 ; i>=0; i=(i/2)-1)
	{
		show(x,i,n+1);
	}
}
void main()
{
	int i;
	int n;
	int a;
	printf("Enter array size: ");
	scanf("%d",&n);
	int x[n];
	for(i = 0; i<n; i++)
	{
		scanf("%d",&a);
		insertdemo(x,a,i);
	}
	deletedemo(x,n);
	for(i = 0; i<n; i++)
	{
		printf("%d ",x[i]);
	}	
	
}
