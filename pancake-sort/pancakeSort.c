#include<stdio.h>
#include<stdlib.h>
int findMaxIndex(int *a,int si, int ei)
{
int i;
int maxIndex = si;
for(i=si;i<=ei;i++)if(a[i]>a[maxIndex]) maxIndex = i;
return maxIndex;
}
void flip(int *a, int si, int ei)
{
while(si<ei)
{
a[si] = a[si] + a[ei];
a[ei] = a[si] - a[ei];
a[si] = a[si] - a[ei];
si++;
ei--;
}
}
void pancakeSort(int *a, int si, int ei)
{
int maxIndex;
while(ei>si)
{
maxIndex = findMaxIndex(a,si,ei);
if(maxIndex != ei)
{
flip(a,si,maxIndex);
flip(a,si,ei);
}
ei--;
}
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
pancakeSort(a,0,n-1);
for(i=0;i<n;i++)printf("%d\n",*(a+i));
free(a);
return 0;
}