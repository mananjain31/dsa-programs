#include<stdio.h>
int pallindrome(char *str)
{
	char *p,*q;
	for(q=str; *q; q++);
	q--;
	for(p=str;p<q && *q==*p; p++,q--);
	return (!(p<q));
}
int main()
{
	printf("%d\n", pallindrome("malayalam"));
	printf("%d\n", pallindrome("mala012yalam"));
}