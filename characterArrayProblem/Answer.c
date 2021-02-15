#include<stdio.h>
void rev(char x[], int i, int j)
{
	j--;
	while(i<j)
	{
		char t = x[i];
		x[i] = x[j];
		x[j] = t;
		i++;
		j--;
	}
}
int main()
{
	char x[]="i am manan jain  31 ";
	printf("%s\n",x);
	int n = sizeof(x);
	n--;
	// printf("%d\n",n);
	int j =0;
	int i;
	while(j<=n)
	{
		while(x[j] == ' ' && j<n) j++;
		if(j == n) break;
		i = j;
		while(x[j] != ' ' && j<n) j++;
		if(j == n+1)
		{
			rev(x,i,j);
			break;
		}
		if(i!=j) rev(x,i,j);
	}
	rev(x,0,n);
	printf("%s\n",x);
}