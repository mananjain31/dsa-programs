#include<stdio.h>
void display(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void combSort(int a[], int n)
{
	int gap,j;
	for(gap = n/1.3; gap > 0; gap/=1.3)
	{
		for(j=gap; j<n; j++)
		{
			if(a[j] < a[j-gap])
			{
				a[j] = a[j] + a[j-gap];
				a[j-gap] = a[j] - a[j-gap];
				a[j] = a[j] - a[j-gap];
			}
			display(a,n);
		}
		printf("\n");
	}
}
void main()
{
	int i,a[]={4,0,2,3,7,1,8,5,9,6};
	int n = sizeof(a)/sizeof(a[0]);
	printf("some output for understanding:\n");
	combSort(a,n);
	printf("\nsorted array:\n");
	display(a,n);
}