#include<stdio.h>
int binarySearch(int x[], int i, int j, int data)
{
	int mid = (i+j)/2;
	if (i>j)
		return -1;
	else if(x[mid] == data)
		return mid;
	else if(x[mid] < data)
		return binarySearch(x,mid+1,j,data);
	else if(x[mid] > data)
		return binarySearch(x,i,mid-1,data);
}

int main()
{
	int data;
	int x[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(x)/sizeof(x[0]);
	printf("Enter No. to search : ");
	scanf("%d",&data);
	int i=0,j=n-1,mid;
	int index;
	index = binarySearch(x,0,n-1,data);
	if(index == -1)
		printf("Data not found\n");
	else
		printf("data Found at index : %d\n", index);
	return 0;
}