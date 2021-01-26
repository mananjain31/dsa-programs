#include<stdio.h>
void main()
{
	int i=1,n,n1,r=0;
	printf("Enter no. of rows: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		r = r*10 +i;
		printf("%d\n",r);
	}
}