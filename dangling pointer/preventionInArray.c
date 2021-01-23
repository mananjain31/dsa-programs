#include<stdio.h>
// preventing dangling Pointer
int* show(int x[], int y[])
{
	int i;
	static int z[5];
	for(i=0; i<5; i++)
	{
		z[i] = x[i] + y[i];
	}
	return z;
}
void main()
{
	int i;
	int x[] = {10,20,30,40,50};
	int y[] = {1,2,3,4,5};
	int *p = show(x,y);
	for(i=0; i<5; i++)
	{
		printf("%d  ",*p);
		p++;
	}
}


