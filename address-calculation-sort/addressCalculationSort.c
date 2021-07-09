#include<stdio.h>
#include<stdlib.h>
int hash(int value, int pos)//order preserving
{
int key;
key = value / pos;
return key;
}
void addressCalculationSort(int *a, int si, int ei)
{
int pos,max,len,i;
max = a[si];
for(i=si;i<=ei;i++) if(max<a[i]) max = a[i];
pos = 1;
while(max/pos != 0) pos*=10;
pos = pos/10;
for(i=si;i<=ei;i++)printf("%d -> %d\n",a[i],hash(a[i],pos));
}

int main()
{
int n,i;
int *a;
printf("Enter Collection size : ");
scanf("%d", &n);
a = (int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
printf("Enter a Number : ");
scanf("%d", a+i);
}
addressCalculationSort(a,0,n-1);
for(i=0;i<n;i++)printf("%d\n",*(a+i));
free(a);
return 0;
}