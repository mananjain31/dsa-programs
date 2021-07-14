#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count = 0;
void swap(char* i, char* j)
{
	char t = *i;
	*i = *j;
	*j = t;
}
void _findAllCombinations(char* str,int s, int e)
{
int i;
if(s==e)
{
printf("%s\n",str);
count++;
return;
}
for(i=s;i<=e;i++)
{
swap(str+s,str+i);
_findAllCombinations(str,s+1,e);
swap(str+s,str+i);
}
}
void findAllCombinations(char* str)
{
_findAllCombinations(str,0,strlen(str)-1);
}
int main()
{
	char c[] = "hijk";
	findAllCombinations(c);
	printf("Count : %d\n", count);
	return 0;
}