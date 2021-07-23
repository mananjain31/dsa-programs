#include<stdio.h>

void printMatrix(int r, int c, int a[r][c])
{
	int i,j;
	printf("      ");
	for (i = 0; i < c; ++i) printf("%5d ", i);
	printf("\n");
	for (i = 0; i < r; ++i)
	{
		printf("%5d ", i);
		for(j=0;j<c;j++)
		{
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int A[2][2] = {
		{1,2},
		{3,4}
	};
	int B[2][2] = {
		{10,20},
		{30,40}
	};
	int C[2][2];


	//Matrix multiplication : 
	C[0][0] = (A[0][0] * B[0][0]) + (A[0][1] * B[1][0]);
	C[0][1] = (A[0][0] * B[0][1]) + (A[0][1] * B[1][1]);
	C[1][0] = (A[1][0] * B[0][0]) + (A[1][1] * B[1][0]);
	C[1][1] = (A[1][0] * B[0][1]) + (A[1][1] * B[1][1]);

	printMatrix(2, 2, A);
	printMatrix(2, 2, B);
	printMatrix(2, 2, C);
	return 0;
}