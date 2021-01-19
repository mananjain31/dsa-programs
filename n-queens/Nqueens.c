#include<stdio.h>
#include<stdbool.h>
/*
you can change the value of N in below
statement for the no. of queens and the 
N x N size of board to make output for

*/
#define N 8
void printArray(int x[N][N]);

bool isValid(int x[N][N], int r, int c)
{
	int i,j;
	
	//checking the column
	for(i = r; i>=0; i--)
		if(x[i][c])return false;
	
	//checking \ direction
	for(i=r,j=c; i>=0 && j>=0; i--, j--)
		if(x[i][j])return false;

	//checking / direction
	for(i=r,j=c; i>=0 && j<N; i--, j++)
		if(x[i][j])return false;
	
	return true;
}

bool show(int x[N][N], int r)
{
	int j;
	if(r==N)return true;
	for(j=0;j<N;j++)
		if(isValid(x,r,j))
		{
			x[r][j] = 1;
			if(show(x,r+1))return true;
			x[r][j] = 0;
		}
		
	return false;	
}

void main()
{
	int x[N][N]={0};
	show(x,0);	
	printArray(x);
}
void printArray(int x[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d  ",x[i][j]);
		}
		printf("\n");
	}
}