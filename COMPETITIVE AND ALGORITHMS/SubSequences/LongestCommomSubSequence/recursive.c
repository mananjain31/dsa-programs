#include<stdio.h>
int x[6] = {65, 66, 67, 68, 80, 90};
int y[4] = {66, 90, 68, 90};
int lenX = 6;
int lenY = 4;
int getLenOfLCS(int e, int f)
{
	int leftSide, rightSide;
	if(e == lenX || f==lenY) return 0;
	if(x[e] == y[f]) return 1+getLenOfLCS(e+1, f+1);
	leftSide = getLenOfLCS(e+1, f);
	rightSide = getLenOfLCS(e, f+1);
	return (leftSide > rightSide) ? leftSide : rightSide;
}
int getLengthOfLCS()
{
	return getLenOfLCS(0,0);
}

int main()
{
	printf("Length of longest common substring : %d\n", getLengthOfLCS());
}