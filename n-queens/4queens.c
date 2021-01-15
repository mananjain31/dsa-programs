#include<stdio.h>
#include<stdbool.h>
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
void main()
{
	int x[4][4]={
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	// if(isValid(x,3,3));
	// {
		// x[3][3] = 1;
	// }
	showArray(x);
}