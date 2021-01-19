#include<stdio.h>
#include<stdbool.h>
void printArray(int x[4][4]);

bool isValid(int x[4][4], int r, int c)
{
	int i,j;
	
	//checking the column
	for(i = r; i>=0; i--)
		if(x[i][c])return false;
	
	//checking \ direction
	for(i=r,j=c; i>=0 && j>=0; i--, j--)
		if(x[i][j])return false;

	//checking / direction
	for(i=r,j=c; i>=0 && j<4; i--, j++)
		if(x[i][j])return false;
	
	return true;
}

bool show(int x[4][4], int r)
{
	int j;
	if(r==4)return true;
	for(j=0;j<4;j++)
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
	int x[4][4]={0};
	show(x,0);	
	printArray(x);
}
void printArray(int x[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d  ",x[i][j]);
		}
		printf("\n");
	}
}