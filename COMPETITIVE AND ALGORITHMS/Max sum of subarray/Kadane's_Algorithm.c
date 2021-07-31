#include <stdio.h>
#include <stdlib.h>
int allNeg(int a[], int n)
{
}
int main(){
	int n,i,j,localMax, maxSum, clb, cub, mlb, mub;
	int *a;
	printf("Enter size of array : ");
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++){
		printf("Enter a number : ");
		scanf("%d", &a[i]);
	}

 	i = 0;
 	j = 0;
    for(i=0; i<n; i++)
    {
        if(a[i]>0) break;
        else if(a[j] < a[i]) j = i;
    }
    if(i==n)
    {   	
	    printf("Maximum Subarray Sum : %d\n", a[j]);
	    printf("Maximum Subarray Sum Range  : %d to %d\n", j, j);
	    return 0;
    }
    localMax = 0;
    maxSum = 0;
    clb = cub = mlb = mub = -1;
    for(;i<n;i++)
    {
        localMax += a[i];
        if(localMax < 0)
        {
        	localMax = 0;
        	cub = clb = -1;
        }
        else
        {
        	if(clb == -1 && cub == -1)
        	{
        		clb = cub = i;
        	}
        	else
        	{
        		cub = i;
        	}
	        
	        if(maxSum < localMax)
	        {
	        	maxSum = localMax;
	        	mlb = clb;
	        	mub = cub;
	        }
	    }
    }
    printf("Maximum Subarray Sum : %d\n", maxSum);
    printf("Maximum Subarray Sum Range  : %d to %d\n", mlb, mub);
	return 0;
}