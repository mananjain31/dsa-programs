#include<stdio.h>
int main()
{
    int v[] = { 5,2,6,4,5,3 };
	int w[] = { 1,5,10,15,20,22 };
    int capacity = 25;
    int size = sizeof(v) / sizeof(v[0]);

    int i,j,num1,num2;
    int dp[size+1][capacity+1];
    for(i=0;i<=capacity;i++)dp[0][i] = 0;
    for(i=0;i<=size;i++)dp[i][0] = 0;

    //i -> row and j -> column
    for(i=1;i<=size;i++)
    {
    	for(j=1;j<=capacity;j++)
    	{	
    		num1 = dp[i-1][j];
    		//j -> current capacity
    		if(j >= w[i-1])
    			num2 = dp[i-1][ j - w[i-1] ] + v[i-1];
    		else
    			num2 = 0;

    		dp[i][j] = num1 > num2 ? num1 : num2;
    		printf("%4d ", dp[i][j]);
    	}	
    	printf("\n");
    }


    printf("Maximum value that can be taken away in knapsack with capacity %d is %d\n", capacity, dp[size][capacity]);
}