#include<stdio.h>
#include<stdlib.h>
void binaryInsertionSort(int* a, int lb, int ub)
{
int i,j,mid,num,si,ei;
for(i=1;i<=ub;i++)
{
si = lb;
ei = i-1;
num=a[i];
while(si<=ei)
{
mid = si + (ei-si)/2;
if(a[mid]==num)
{
si = mid;
break;
}
else if(a[mid]<num)si=mid+1;
else if(a[mid]>num)ei=mid-1;
}
for(j=i;j>si;j--)
{
a[j] = a[j-1];
}
a[si] = num;
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
binaryInsertionSort(a,0,n-1);
for(i=0;i<n;i++)printf("%d\n",*(a+i));
free(a);
return 0;
} 