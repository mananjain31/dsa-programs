#include<stdio.h>
//recursive matrix multiplication for square matrix of dimenstions in powers of 2
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

int dim = 4;
int A[4][4] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16}
};
int B[4][4] = {
	{10,20,30,40},
	{50,60,70,80},
	{90,100,110,120},
	{130,140,150,160}
};
int C[4][4];

void multiply(int crlb,int crub, int cclb, int ccub, int arlb,int arub, int aclb, int acub, int brlb,int brub, int bclb, int bcub, int n)
{
	if(n == 2)
	{
		// C[0][0] = (A[0][0] * B[0][0]) + (A[0][1] * B[1][0]);
		// C[0][1] = (A[0][0] * B[0][1]) + (A[0][1] * B[1][1]);
		// C[1][0] = (A[1][0] * B[0][0]) + (A[1][1] * B[1][0]);
		// C[1][1] = (A[1][0] * B[0][1]) + (A[1][1] * B[1][1]);
		C[crlb][cclb] += (A[arlb][aclb] * B[brlb][bclb]) + (A[arlb][acub] * B[brub][bclb]);
		C[crlb][ccub] += (A[arlb][aclb] * B[brlb][bcub]) + (A[arlb][acub] * B[brub][bcub]);
		C[crub][cclb] += (A[arub][aclb] * B[brlb][bclb]) + (A[arub][acub] * B[brub][bclb]);
		C[crub][ccub] += (A[arub][aclb] * B[brlb][bcub]) + (A[arub][acub] * B[brub][bcub]);
		
	}
	else
	{
// C[0][0] = (A[0][0] * B[0][0]) + (A[0][1] * B[1][0]);
// C[0][1] = (A[0][0] * B[0][1]) + (A[0][1] * B[1][1]);
// C[1][0] = (A[1][0] * B[0][0]) + (A[1][1] * B[1][0]);
// C[1][1] = (A[1][0] * B[0][1]) + (A[1][1] * B[1][1]);
multiply(crlb,(crub+crlb)/2, cclb,(ccub+cclb)/2,  arlb, (arub+arlb)/2,  aclb,  (acub+aclb)/2,  brlb, (brub+brlb)/2,  bclb,  (bcub+bclb)/2,  n/2);
multiply(crlb,(crub+crlb)/2, cclb,(ccub+cclb)/2,  arlb, (arub+arlb)/2,  ((acub+aclb)/2) +1,  acub,  ((brub+brlb)/2)+1, brub, bclb,  (bcub+bclb)/2,  n/2);

multiply(crlb,(crub+crlb)/2, ((ccub+cclb)/2)+1, ccub, arlb, (arub+arlb)/2,  aclb,  (acub+aclb)/2,  brlb, (brub+brlb)/2,  ((bcub+bclb)/2)+1, bcub,  n/2);
multiply(crlb,(crub+crlb)/2, ((ccub+cclb)/2)+1, ccub,  arlb, (arub+arlb)/2,  ((acub+aclb)/2) +1,  acub,  ((brub+brlb)/2)+1, brub, ((bcub+bclb)/2)+1, bcub,  n/2);

multiply(((crub+crlb)/2)+1,crub, cclb,(ccub+cclb)/2, ((arub+arlb)/2)+1,arub, aclb,  (acub+aclb)/2,  brlb, (brub+brlb)/2,  bclb,  (bcub+bclb)/2,  n/2);
multiply(((crub+crlb)/2)+1,crub, cclb,(ccub+cclb)/2,  ((arub+arlb)/2)+1,arub,  ((acub+aclb)/2) +1,  acub,  ((brub+brlb)/2)+1, brub, bclb,  (bcub+bclb)/2,  n/2);

multiply(((crub+crlb)/2)+1,crub, ((ccub+cclb)/2)+1, ccub, ((arub+arlb)/2)+1, arub,  aclb,  (acub+aclb)/2,  brlb, (brub+brlb)/2,  ((bcub+bclb)/2)+1, bcub,  n/2);
multiply(((crub+crlb)/2)+1,crub, ((ccub+cclb)/2)+1, ccub, ((arub+arlb)/2)+1, arub,  ((acub+aclb)/2) +1,  acub,  ((brub+brlb)/2)+1, brub, ((bcub+bclb)/2)+1, bcub,  n/2);

	}
}

int main()
{
	int i,j;
	for(i=0;i<4;i++)for(j=0;j<4;j++)C[i][j] = 0;
	multiply(0,3,0,3, 0,3,0,3, 0,3,0,3, 4);

	printMatrix(4, 4, A);
	printMatrix(4, 4, B);
	printMatrix(4, 4, C);
	return 0;
}