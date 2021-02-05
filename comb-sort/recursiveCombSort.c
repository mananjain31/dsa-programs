#include<stdio.h>
void display(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void combSort(int a[], int g,  int n)
{
	int j;
	if(g == 0) return;
	g=g/1.3;
	for(j=g; j<n; j++)
	{
		if(a[j] < a[j-g])
		{
			a[j] = a[j] + a[j-g];
			a[j-g] = a[j] - a[j-g];
			a[j] = a[j] - a[j-g];
		}
		display(a,n);
	}
	printf("\n");
	combSort(a,g,n);
}
void main()
{
	int i,a[]={4,0,2,3,7,1,8,5,9,6};
	int n = sizeof(a)/sizeof(a[0]);
	printf("some output for understanding:\n");
	combSort(a,n,n);
	printf("\nsorted array:\n");
	display(a,n);
}

//output
/*
some output for understanding:
4 0 2 3 7 1 8 5 9 6
4 0 2 3 7 1 8 5 9 6
4 0 2 3 7 1 8 5 9 6

1 0 2 3 7 4 8 5 9 6
1 0 2 3 7 4 8 5 9 6
1 0 2 3 7 4 8 5 9 6
1 0 2 3 7 4 8 5 9 6
1 0 2 3 6 4 8 5 9 7

1 0 2 3 6 4 8 5 9 7
1 0 2 3 6 4 8 5 9 7
1 0 2 3 6 4 8 5 9 7
1 0 2 3 6 4 8 5 9 7
1 0 2 3 5 4 8 6 9 7
1 0 2 3 5 4 8 6 9 7
1 0 2 3 5 4 7 6 9 8

1 0 2 3 5 4 7 6 9 8
1 0 2 3 5 4 7 6 9 8
1 0 2 3 5 4 7 6 9 8
1 0 2 3 5 4 7 6 9 8
1 0 2 3 5 4 7 6 9 8
1 0 2 3 5 4 7 6 9 8
1 0 2 3 5 4 7 6 9 8
1 0 2 3 5 4 7 6 9 8

0 1 2 3 5 4 7 6 9 8
0 1 2 3 5 4 7 6 9 8
0 1 2 3 5 4 7 6 9 8
0 1 2 3 5 4 7 6 9 8
0 1 2 3 4 5 7 6 9 8
0 1 2 3 4 5 7 6 9 8
0 1 2 3 4 5 6 7 9 8
0 1 2 3 4 5 6 7 9 8
0 1 2 3 4 5 6 7 8 9

0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9


sorted array:
0 1 2 3 4 5 6 7 8 9
*/
