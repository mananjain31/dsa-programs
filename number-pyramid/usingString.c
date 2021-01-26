#include<stdio.h>
#include<string.h>
void main()
{
	int i;
	char y[200]="";
	char x[200]="";
	int n;
	printf("Enter number of rows: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{	
		sprintf(y,"%d",i);
		strcat(x,y);
		printf("%s\n",x);
	}
}
