#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void stats(char *c)
{
int a,b,totalContinuous,size,min,max,sorted;
sorted = 1;
size = 0;
totalContinuous = 0;
FILE *file;
printf("File : %s\n", c);
file = fopen(c, "rb");
if(file == NULL)
{
printf("File Not Found");
return;
}
if(fread(&a, sizeof(int), 1, file) < 1) 
{
printf("empty file");
return;
}
size++;
min = a;
max = a;
while(fread(&b, sizeof(int), 1, file))
{
// printf("%d ",b);
size++;
if(a==b) totalContinuous++;
if(a>b)
{
sorted = 0; 
// printf("a = %d, b = %d index = %d\n",a,b,size);	
// break;
} 
a = b;
if(b < min) min = b;
if(b > max) max = b;
}
printf("size = %d\n",size);
printf("%s\n",sorted?"Sorted":"Not Sorted");
if(sorted)
{
printf(" totalContinuous = %d\n",totalContinuous);
printf(" size-totalContinuous = %d\n",size-totalContinuous);
}
printf("min = %d\n",min);
printf("max = %d\n",max);
fclose(file);
}
int main()
{
char c[100];
printf("Enter File Name : ");
scanf("%s",c);
stats(c);
return 0;
}