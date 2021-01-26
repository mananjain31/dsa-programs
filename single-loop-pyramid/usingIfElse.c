//Using goto solving single-loop-pyramid 
#include<stdio.h>
void main()
{
	printf("Enter height of pyramid: ");
	int n;
	scanf("%d",&n);
	int i=1,j=1;
	while(i<=n)
	{
		if(j==i)
		{
			printf("*\n");
			i++;
			j=1;
		}
		else
		{
			printf("*");
			j++;
		}
	}
}