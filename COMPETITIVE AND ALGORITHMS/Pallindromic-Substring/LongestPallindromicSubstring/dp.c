#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
	char a[]="accaac";
	int i,j,k,maxsp=-1, maxep=-1, maxLen=0;
	int len, sp, ep;
	len =strlen(a);
	bool dp[len][len];
	for(k=1;k<len;k++)
	{
		j=k;
		i=0;
		while(j<len)
		{
			if(i+1 == j) dp[i][j] = (a[i] == a[j]);
			else if(a[i]==a[j]) 
			{
				if(i==j) dp[i][j] = true;
				else if(i>j) dp[i][j] = false;
				else if(j-i == 1) dp[i][j] = true;
				else if(i+1 == j-1) dp[i][j] = true;
				else if(i+1 > j-1) dp[i][j] = false;
				else dp[i][j] = dp[i+1][j-1];
			}
			else dp[i][j] = false;

			if(dp[i][j] & j-i+1 > maxLen)
			{
				maxLen = j-i+1;
				maxsp = i;
				maxep = j;
			}
			j++;
			i++;
		}
	}
	if(maxLen == 0){
		maxLen = 1;
		maxsp = 0;
		maxep = 0;
	}
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)printf("%d ", dp[i][j]!=1?0:1);
		printf("\n");
	}
	printf("Max Length = %d, Starting index = %d, Ending Index = %d\n",
		maxLen, maxsp, maxep);
	for(i=maxsp;i<=maxep;i++) printf("%c", a[i]);
	return 0;
	/*
	* 0 1 2 3 4 
	0 t 
	1 f t
	2 f f t
	3 f f f t
	4 f f f f t
	*/
}