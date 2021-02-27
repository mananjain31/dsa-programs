#include<stdio.h>

int main()
{
	int data;
	int x[] = {10, 20, 30, 40, 50, 60, 70, 80};
	printf("Enter No. to search : ");
	scanf("%d",&data);
	for(int i = 0; i < sizeof(x)/sizeof(x[0]); i++)
	{
		if(x[i] == data)
		{
			printf("data found at index : %d\n", i);
			return 0;
		}
	}
	printf("Data not found\n");
	return 0;
}