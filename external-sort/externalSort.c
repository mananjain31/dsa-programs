//external sort program
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quickSort(int a[], int si, int end)
{
if(si >= end) return;
int pivot = a[end];
int p = si;
int t,i;
for(i = si; i < end; i++)
{
if(a[i] < pivot)
{
t = a[i];
a[i] = a[p];
a[p] = t;
p++;
}
}
t = a[end];
a[end] = a[p];
a[p] = t;
quickSort(a, si, p-1);
quickSort(a, p+1, end);	
}
int main()
{
long noOfBytes, noOfNumbers;
int n,noOfParts = 10;
FILE *f = fopen("data.d", "rb");
fseek(f,0, SEEK_END);
noOfBytes = ftell(f);
noOfNumbers = noOfBytes / sizeof(int);
n = noOfNumbers/noOfParts;
fclose(f);

f = fopen("data.d", "rb");
int *part;
part = (int*)malloc(sizeof(int)*n);
for(int j=0;j<10;j++)
{
//get values into array
fread(part, sizeof(int)*n, 1, f);
//sort the array
quickSort(part,0,n-1);
//write in the file
FILE *smallF;
if(j==0)smallF = fopen("smalldata0.d", "wb");
else if(j==1)smallF = fopen("smalldata1.d", "wb");
else if(j==2)smallF = fopen("smalldata2.d", "wb");
else if(j==3)smallF = fopen("smalldata3.d", "wb");
else if(j==4)smallF = fopen("smalldata4.d", "wb");
else if(j==5)smallF = fopen("smalldata5.d", "wb");
else if(j==6)smallF = fopen("smalldata6.d", "wb");
else if(j==7)smallF = fopen("smalldata7.d", "wb");
else if(j==8)smallF = fopen("smalldata8.d", "wb");
else if(j==9)smallF = fopen("smalldata9.d", "wb");

fwrite(part, sizeof(int)*n, 1, smallF);
fclose(smallF);
}
fclose(f);

FILE *f2 = fopen("data2.d", "wb");
FILE *small0 = fopen("smalldata0.d", "rb");
FILE *small1 = fopen("smalldata1.d", "rb");
FILE *small2 = fopen("smalldata2.d", "rb");
FILE *small3 = fopen("smalldata3.d", "rb");
FILE *small4 = fopen("smalldata4.d", "rb");
FILE *small5 = fopen("smalldata5.d", "rb");
FILE *small6 = fopen("smalldata6.d", "rb");
FILE *small7 = fopen("smalldata7.d", "rb");
FILE *small8 = fopen("smalldata8.d", "rb");
FILE *small9 = fopen("smalldata9.d", "rb");
int arr[10];
int test;
fread(&arr[0],sizeof(int),1,small0);
fread(&arr[1],sizeof(int),1,small1);
fread(&arr[2],sizeof(int),1,small2);
fread(&arr[3],sizeof(int),1,small3);
fread(&arr[4],sizeof(int),1,small4);
fread(&arr[5],sizeof(int),1,small5);
fread(&arr[6],sizeof(int),1,small6);
fread(&arr[7],sizeof(int),1,small7);
fread(&arr[8],sizeof(int),1,small8);
fread(&arr[9],sizeof(int),1,small9);
int hasData[10] = {1,1,1,1,1,1,1,1,1,1};
int min = 0;
for(int m=0;m<n*10;m++)
{
//get index with minimum element
for(int i=0;i<10;i++)
{
if(hasData[i] == 1 && arr[i]<=arr[min])
{
min = i;
}
}
//write min element into file
fwrite(&arr[min], sizeof(int), 1, f2);
if(min==0){ if(fread(&arr[min],sizeof(int),1,small0) <= 0) hasData[min] = 0;}
else if(min==1){ if(fread(&arr[min],sizeof(int),1,small1) <= 0) hasData[min] = 0;}
else if(min==2){ if(fread(&arr[min],sizeof(int),1,small2) <= 0) hasData[min] = 0;}
else if(min==3){ if(fread(&arr[min],sizeof(int),1,small3) <= 0) hasData[min] = 0;}
else if(min==4){ if(fread(&arr[min],sizeof(int),1,small4) <= 0) hasData[min] = 0;}
else if(min==5){ if(fread(&arr[min],sizeof(int),1,small5) <= 0) hasData[min] = 0;}
else if(min==6){ if(fread(&arr[min],sizeof(int),1,small6) <= 0) hasData[min] = 0;}
else if(min==7){ if(fread(&arr[min],sizeof(int),1,small7) <= 0) hasData[min] = 0;}
else if(min==8){ if(fread(&arr[min],sizeof(int),1,small8) <= 0) hasData[min] = 0;}
else if(min==9){ if(fread(&arr[min],sizeof(int),1,small9) <= 0) hasData[min] = 0;}

}
fclose(small0);
fclose(small1);
fclose(small2);
fclose(small3);
fclose(small4);
fclose(small5);
fclose(small6);
fclose(small7);
fclose(small8);
fclose(small9);
fclose(f2);
printf("done");
return 0;
}