#include<stdio.h>
void mergeSort(int[],int);
void merge();
void display(int[],int);

void mergeSort(int x[], int n)
{
	if(n==1)return;
	int i;
	int m1 = n/2;
	int m2 = n-m1;
	int a[m1],b[m2];
	for(i=0;i<m1;i++) a[i] = x[i];
	for(i=0;i<m2;i++) b[i] = x[m1+i];
	mergeSort(a,m1);
	mergeSort(b,m2);
}

void main()
{
	int n,i;
	printf("Enter No. of elements to perform Merge sort: ");
	scanf("%d", &n);
	int x[n];
	for(i = 0; i<n; i++)
	{
		printf("Enter %d numbered value: ",i+1);
		scanf("%d",&x[i]);
	}
	mergeSort(x,n);
	printf("Sorted Array is : \n");
	display(x,n);
}
void display(int x[], int n)
{
	int i;
	for(i=0;i<n;i++)printf("%d ", x[i]);
}