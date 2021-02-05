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
//output:
/*
some output for understanding:
5 6 3 1 9 7 2 4 1
5 3 6 1 9 7 2 4 1
5 3 1 6 9 7 2 4 1
5 3 1 6 9 7 2 4 1
5 3 1 6 7 9 2 4 1
5 3 1 6 7 2 9 4 1
5 3 1 6 7 2 4 9 1
5 3 1 6 7 2 4 1 9

3 5 1 6 7 2 4 1 9
3 1 5 6 7 2 4 1 9
3 1 5 6 7 2 4 1 9
3 1 5 6 7 2 4 1 9
3 1 5 6 2 7 4 1 9
3 1 5 6 2 4 7 1 9
3 1 5 6 2 4 1 7 9

1 3 5 6 2 4 1 7 9
1 3 5 6 2 4 1 7 9
1 3 5 6 2 4 1 7 9
1 3 5 2 6 4 1 7 9
1 3 5 2 4 6 1 7 9
1 3 5 2 4 1 6 7 9

1 3 5 2 4 1 6 7 9
1 3 5 2 4 1 6 7 9
1 3 2 5 4 1 6 7 9
1 3 2 4 5 1 6 7 9
1 3 2 4 1 5 6 7 9

1 3 2 4 1 5 6 7 9
1 2 3 4 1 5 6 7 9
1 2 3 4 1 5 6 7 9
1 2 3 1 4 5 6 7 9

1 2 3 1 4 5 6 7 9
1 2 3 1 4 5 6 7 9
1 2 1 3 4 5 6 7 9

1 2 1 3 4 5 6 7 9
1 1 2 3 4 5 6 7 9

1 1 2 3 4 5 6 7 9



sorted array:
1 1 2 3 4 5 6 7 9
*/