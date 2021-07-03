#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,i,j,max;
int *a,*b;
printf("Enter no. of elements : ");
scanf("%d",&n);
a = (int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
printf("enter a number : ");
scanf("%d", &a[i]);
}
max = a[0];
for(i=0;i<n;i++)if(max < a[i]) max = a[i];
b = (int*)malloc(sizeof(int)*max+1);
for(i=0;i<max+1;i++)b[i] = 0;
for(i=0;i<n;i++)b[a[i]]++;

j=0;
for(i=0;i<max+1;i++)
{
while(b[i]!=0)
{
a[j] = i;
j++;
b[i]--;
}
}

for(i=0;i<n;i++)printf("%d\n",a[i]);
free(a);
free(b);
return 0;
}