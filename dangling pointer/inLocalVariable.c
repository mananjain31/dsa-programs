//dangling pointer concept in local variable
#include<stdio.h>
void main()
{
	int *p;
	{
		int x = 10;
		p = &x;
	}
	printf("%d",*p);
}
