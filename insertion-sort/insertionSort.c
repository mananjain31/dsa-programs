//Insertion Sort Program in c 
#include<stdio.h>
void insertionSort(int x[], int n)
{
	int i,j;
	for(i=1; i<n; i++)
	{
		int value = x[i];
		for(j=i-1;j>=0;j--)
		{
			if(value < x[j])
				x[j+1] = x[j];
			else break;
		}
		x[j+1] = value;
	}
}
void display(int x[], int n)
{
	for(int i=0;i<n;i++) 
		printf("%d ",x[i]);
}
void main()
{
	int n;
	printf("Enter Size of array: ");
	scanf("%d",&n);
	int x[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter %d numbered value: ",i+1);
		scanf("%d",&x[i]);
	}
	insertionSort(x, n);
	printf("Sorted Array after Insertion Sort is: \n");
	display(x, n);
}