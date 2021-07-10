#include<stdio.h>
#include<stdlib.h>
void swapIfGreater(int *first, int *last)
{
if(*first > *last)
{
*first = *first + *last;
*last = *first - *last;
*first = *first - *last;
}
}
void stoogeSort(int* a, int lb, int ub)
{
int len = (ub-lb+1);
int twoThird = len - (len/3);
int diff = twoThird-1;
swapIfGreater(a+lb,a+ub);
if(len >= 3)
{
stoogeSort(a,lb,lb+diff); // left
stoogeSort(a,ub-diff,ub); //right
stoogeSort(a,lb,lb+diff); //left
}
}
int main()
{
int n,i;
int *a;
printf("Enter Collection size -> ");
scanf("%d", &n);
a = (int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
printf("Enter a Number : ");
scanf("%d", a+i);
}
stoogeSort(a,0,n-1);
for(i=0;i<n;i++)printf("%d\n",*(a+i));
free(a);
return 0;
}