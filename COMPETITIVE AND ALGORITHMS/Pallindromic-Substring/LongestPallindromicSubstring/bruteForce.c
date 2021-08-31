#include<stdio.h>
#include<string.h>
struct data
{	
	int length;
	int pallindrome;
};
struct data isPallindrome(char *str, int e, int f)
{
	struct data ds;
	char *p,*q, *sp, *ep;
	sp = str+e;
	ep = str+f;
	for(q=sp; q<ep; q++);
	ds.length = f-e+1;
	for(p=sp;p<q && *q==*p; p++,q--);
	ds.pallindrome = (!(p<q));
	return ds;
}
void print(char *str, int e, int f)
{
	char *sp, *ep;
	sp = str+e;
	ep = str+f;
	while(sp<=ep)
	{
		printf("%c", *sp);
		sp++;
	}
	printf("\n");
}
int main()
{
	char a[7]="accaac";
	int e,f,g;
	int len;
	len =strlen(a);
	for(e=0;e<len;e++)
	{
		for(f=e;f<len;f++)
		{
			struct data ds = isPallindrome(a, e, f);
			if(ds.pallindrome)
			{
				print(a,e,f);
				printf("Length : %d, pallindrome : %d\n", ds.length, ds.pallindrome);
			}
		}
	}
	return 0;
}