//Time complexity = O(N^2)
//Space Complexity = O(1)
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,j,invCount;
	int* a;
	printf("Enter Size of array : ");
	scanf("%d", &n);
	a = (int*) malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		printf("Enter a number : ");
		scanf("%d", a+i);
	}
	invCount = 0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])invCount++;
		}
	}
	printf("Inversion Count : %d\n", invCount);
	free(a);
	return 0;
}
//6 4 12 3 32 76 54 19 27 62