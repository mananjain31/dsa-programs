#include<stdio.h>
int main()
{
	int data;
	int x[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(x)/sizeof(x[0]);
	printf("Enter No. to search : ");
	scanf("%d",&data);
	int i=0,j=n-1,mid;
	int index = -1;
	
	while(1)
	{
		mid = (i+j)/2; 
		if(i>j) break;
		if(x[mid] == data)
		{
			index = mid;
			break;
		}
		else if(x[mid] < data)
		{
			i = mid+1;
		}
		else if(x[mid] > data)
		{
			j = mid-1;
		}
	}
	if(index == -1)
		printf("Data not found\n");
	else
		printf("data Found at index : %d\n", index);
	return 0;
}