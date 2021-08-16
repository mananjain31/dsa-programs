#include<stdio.h>
int x[6] = {65, 66, 67, 68, 80, 90};
int y[4] = {66, 90, 68, 90};
int lenX = 6;
int lenY = 4;
int dp[6][4];
int getLenOfLCS(int e, int f)
{
	int l,r;
	if(e == lenX || f == lenY) return 0;
	if(dp[e][f] != -1) return dp[e][f];
	if(x[e] == y[f]) return dp[e][f]  = 1 + getLenOfLCS(e+1, f+1);;
	l = getLenOfLCS(e+1, f);
	r = getLenOfLCS(e, f+1);
	return dp[e][f] = l > r ? l : r;
}
int getLengthOfLCS()
{
	for(int i=0;i<6;i++)for(int j=0;j<4;j++) dp[i][j] = -1;
	return getLenOfLCS(0,0);
}

int main()
{
	printf("Length of longest common substring : %d\n", getLengthOfLCS());
}