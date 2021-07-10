#include<stdio.h>
#include<stdlib.h>
void cockTailSort(int* a, int lb, int ub)
{
int i,swapped;
while(lb<ub)
{
//going right
swapped = 0;
for(i=lb;i<ub;i++)
{
if(a[i]>a[i+1])
{
a[i] = a[i] + a[i+1];
a[i+1] = a[i] - a[i+1];
a[i] = a[i] - a[i+1];
swapped = 1;
}
}
ub--;
if(!swapped) break; 
//going left
swapped = 0;
for(i=ub;i>lb;i--)
{
if(a[i-1]>a[i])
{
a[i-1] = a[i-1] + a[i];
a[i] = a[i-1] - a[i];
a[i-1] = a[i-1] - a[i];
swapped = 1;
}
}
lb++;
if(!swapped) break;
}
}
int main()
{
int n,i;
int *a;
printf("Enter no. of elements -> ");
scanf("%d",&n);
a = (int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
printf("enter a number : ");
scanf("%d", a+i);
}
cockTailSort(a,0,n-1);
for(i=0;i<n;i++)printf("%d\n",a[i]);
free(a);
return 0;
}