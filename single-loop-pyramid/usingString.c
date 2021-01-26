//Using String solving single-loop-pyramid 
#include<stdio.h>
#include<string.h>
void main()
{
	int i;
	int n = 5;
	char s[n];
	s[0]='*';
	for(i=0;i<n;i++)
	{	
		printf("%s\n",s);	
		strcat(s,"*");
	}
}