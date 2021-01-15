#include<stdio.h>
#include<stdbool.h>
void showArray(int x[4][4]);

bool isValid(int x[4][4], int r, int c)
{
	int i,j;
	//checking the row
	for(j = c; j>=0; j--)
		if(x[r][j])return false;
	
	//checking the column
	for(i = r; i>=0; i--)
		if(x[i][c])return false;
	
	return true;
}

void main()
{
	int x[4][4]={
		{0,1,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	int i=1, j=1;
	if(isValid(x,i,j))
	{
		x[i][j] = 1;
	}
	showArray(x);
}
void showArray(int x[4][4])
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