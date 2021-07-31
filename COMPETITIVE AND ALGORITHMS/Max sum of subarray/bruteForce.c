#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,j,sum,maxSum = INT_MIN;
	int *a;
	printf("Enter size of array : ");
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++){
		printf("Enter a number : ");
		scanf("%d", &a[i]);
	}
	for(i = 0; i < n; i++){
		sum = 0;
		for(j = i; j < n; j++){
			sum+=a[j];
			if(sum > maxSum) maxSum = sum;
		}
	}
	printf("Max Sum : %d\n", maxSum);
	return 0;
}