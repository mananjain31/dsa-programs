#include<stdio.h>

void show(int n,char from, char to, char mid)
{
	if(n>0)
	{
		show(n-1,from,mid,to);
		printf("move a disk from %c to %c\n", from, to);
		show(n-1,mid,to,from);
	}
}

int main()
{
	int n;
	printf("Enter no of disks: ");
	scanf("%d",&n);
	show(n,'A','C','B');
	return 0;
}