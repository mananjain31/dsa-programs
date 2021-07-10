#include<stdio.h>
#include<stdlib.h>
void merge(int* a, int lb1, int ub1, int lb2, int ub2)
{
int i,j,k;
i=lb1;
j=lb2;
k=0;
int* b = (int*)malloc(sizeof(int)*(ub2-lb1+1));
while(i<=ub1 && j<=ub2)
{
if(a[i]<a[j]) b[k] = a[i++];
else b[k] = a[j++];
k++;
}
while(i<=ub1) b[k++] = a[i++];
while(j<=ub2) b[k++] = a[j++];
for(i=lb1;i<=ub2;i++)a[i] = b[i-lb1];
free(b);
}
void insertionSort(int *a, int lb, int ub)
{
int i,t,j;
for(i=lb+1;i<=ub;i++)
{
t = a[i];
for(j=i-1;j>=lb && a[j]>t;j--)
{
a[j+1] = a[j];
}
a[j+1] = t;
}
}
void timSort(int *a, int lb, int ub)
{
int i,j,mid,lb1,lb2,ub1,ub2;
for(i=lb;i<=ub;i+=64)
{
if((ub-i)+1 > 64) j = i+64-1;
else j = ub;
insertionSort(a,i,j);
}
for(mid=lb+64;mid<=ub;mid+=64)
{
lb1 = lb;
ub1 = mid-1;
lb2 = mid;
ub2 = mid+64-1 <=  ub ? mid+64-1 : ub;
merge(a,lb1,ub1,lb2,ub2);
}
}
int main()
{
long n,i;
int x;
int *a;
FILE *f = fopen("data.d","rb");
fseek(f, 0, SEEK_END);
n = ftell(f)/sizeof(int);
a = (int*)malloc(sizeof(int)*n);
if(a)
{
fseek(f, 0, SEEK_SET);
fread(a,sizeof(int)*n,1,f);
fclose(f);
timSort(a,0,n-1);
f = fopen("data2.d", "wb");
fwrite(a,sizeof(int)*n,1,f);
fclose(f);
free(a);
printf("SORTED DATA STORED IN FILE : data2.d\n");
}
else
{
printf("Array memory not allocated\n");
}
return 0;
}