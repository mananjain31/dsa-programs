#include<stdio.h>
#include<stdlib.h>
int power(int* a, int b, int p)
{
if(p == 1) return b;
if(a[p]!=-1)return a[p];
if(p%2 == 0) a[p] = power(a,b,p/2)*power(a,b,p/2);
else a[p] = b*power(a,b,p/2)*power(a,b,p/2);
return a[p];
}
int calculatePower(int b, int p)
{
if(p==1)return b;
int i;
int a[(p/2)+1];
for(i=0;i<(p/2)+1;i++)a[i]=-1;
if(p % 2 == 0) return power(a,b,p/2)*power(a,b,p/2);
return b*power(a,b,p/2)*power(a,b,p/2);
}
int main()
{
int x,y;
printf("Enter number: ");
scanf("%d",&x);
printf("Enter power: ");
scanf("%d",&y);
printf("Result : %d",calculatePower(x,y));
return 0;
}