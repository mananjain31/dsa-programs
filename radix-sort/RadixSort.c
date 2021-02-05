#include<stdio.h>
void display(int[], int);
void show(int x[], int div, int n)
{
	int i;
	int a[10] = {0};
	int y[n];
	for(i = 0; i<n; i++)
		a[(x[i]/div)%10]++;
	
	for(i = 1; i<10; i++)
		a[i]+=a[i-1];

	for(i = n-1; i >= 0; i--)
		y[a[(x[i]/div)%10]-=1] = x[i];

	for(i = 0; i < n; i++)
		x[i] = y[i];
}
void radixSort(int x[], int n)
{
	int i;
	int max = x[0];
	int min = x[0];
	
	for(i=1; i<n; i++)
	{
		if(x[i] < min)
			min = x[i];
	}
	printf("min = %d\n",min);
	for(i = 0; i < n; i++)
	{
		x[i]-=min;
	}
	display(x,n);
	
	for(i=1; i<n; i++)
	{
		if(x[i] > max)
			max = x[i];
	}
	printf("max = %d\n",max);
	for(i = 1; i <= max; i *= 10)
	{
		show(x,i,n);
	display(x,n);
	}
		
	for(i = 0; i < n; i++)
	{
		x[i]+=min;
	}
}
void display(int x[],int n)
{
	int i;
	for(i = 0; i < n; i++) 
		printf("%d ",x[i]);
	printf("\n");
}
void main()
{
	int i;
	int x[] = {44,48,45,-100, 8890, 2, -60, 12, -100, 101, 777777, 0};
	int n = sizeof(x)/sizeof(x[0]);
	printf("some output for understanding:\n");
	radixSort(x,n);
	printf("\nsorted array:\n");
	display(x,n);
}

//output:
/*
some output for understanding:
min = -100
144 148 145 0 8990 102 40 112 0 201 777877 100
max = 777877
0 8990 40 0 100 201 102 112 144 145 777877 148
0 0 100 201 102 112 40 144 145 148 777877 8990
0 0 40 100 102 112 144 145 148 201 777877 8990
0 0 40 100 102 112 144 145 148 201 777877 8990
0 0 40 100 102 112 144 145 148 201 8990 777877
0 0 40 100 102 112 144 145 148 201 8990 777877

sorted array:
-100 -100 -60 0 2 12 44 45 48 101 8890 777777

*/