//Using goto solving single-loop-pyramid 
#include<stdio.h>
void main()
{
	int i;
	printf("enter pyramid height: ");
	int n;
	scanf("%d",&n);
	int k=1;
	M:
	for(i=1;i<=k;i++)
	{
		printf("* ");
	}
	printf("\n");
	if(k>n)return;
	k++;
	goto M;
}