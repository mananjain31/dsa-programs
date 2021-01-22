#include<stdio.h>
void mergeSort(int x[],int n);
void merge(int a[], int b[], int x[], int m1, int m2);
void display(int x[],int n);

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
	merge(a,b,x,m1,m2);
}

void merge(int a[], int b[], int x[], int m1, int m2)
{
	int i=0,j=0,k=0;
	while(i<m1 && j<m2)
		if(a[i] < b[j]) x[k++] = a[i++]; 
		else x[k++] = b[j++]; 
	while(i < m1) x[k++] = a[i++];
	while(j < m2) x[k++] = b[j++];
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