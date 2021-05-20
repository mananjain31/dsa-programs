#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void selectionSort(void* ptr, int lb, int ub, int es,int (*p2f)(void*, void*))
{
int i,j,min;
void *block;
block = (void*)malloc(es);
for(i=lb;i<=ub-1;i++)
{
min = i;
for(j=i+1;j<=ub;j++)
{
	if( p2f( ptr+(min*es), ptr+(j*es) )>0 ) min = j;
}
	memcpy(block,(const void*)(ptr+i*es),es);
	memcpy(ptr+i*es,(const void*)(ptr+min*es),es);
	memcpy(ptr+min*es,(const void*)block,es);
}
free(block);
}


//
int mycomparator(void* a, void* b)
{
int* left = (int*)a;
int* right= (int*)b;
return *left - *right;
}

int main()
{
int req,i;
printf("Enter Collection size : ");
scanf("%d", &req);
int* coll = (int*)malloc(sizeof(int)*req);
for(i=0; i<req; i++)
{
printf("Enter Value : ");
scanf("%d", coll+i);
}
selectionSort(coll,0,req-1,sizeof(int),mycomparator);
for(i=0;i<req;i++)printf("%d ", coll[i]);
free(coll);
return 0;
}
