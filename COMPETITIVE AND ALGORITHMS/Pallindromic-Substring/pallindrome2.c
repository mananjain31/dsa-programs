#include<stdio.h>
struct data
{	
	int length;
	int pallindrome;
};
struct data isPallindrome(char *str)
{
	struct data ds;
	char *p,*q;
	for(q=str; *q; q++);
	ds.length = q-str;
	q--;
	for(p=str;p<q && *q==*p; p++,q--);
	ds.pallindrome = (!(p<q));
	return ds;
}
int main()
{
	struct data d = isPallindrome("malayalam");
	printf("Length %d, isPallindrome %d \n",d.length, d.pallindrome );
	struct data d2 = isPallindrome("malayalamjj");
	printf("Length %d, isPallindrome %d \n",d2.length, d2.pallindrome );
}