#include<stdio.h>
#include<stdlib.h>
typedef struct _bucket_node{
	int data;
	struct _bucket_node* next;
}BucketNode;
typedef struct _bucket{
	BucketNode* start;
	BucketNode* end;
	int size;
}Bucket;

void initBucket(Bucket *bucket)
{
bucket->start = NULL;
bucket->end = NULL;
bucket->size = 0;
}

void sortedInsert(Bucket* bucket, int data)
{
BucketNode* t = (BucketNode*)malloc(sizeof(BucketNode));
if(bucket->start == NULL)
{
//t->data = data;
t->next = NULL;
bucket->start = t;
bucket->end = t;
}
else
{
t->next = bucket->start;
bucket->start = t;
while(t->next != NULL)
{
if(t->next->data > data) break;
t->data = t->next->data;
t = t->next;
}
}
t->data = data;
bucket->size++;
}

int dequeueBucket(Bucket* bucket)
{
int data;
BucketNode* t;
t = bucket->start;
bucket->start = bucket->start->next;
bucket->size--;
data = t->data;
free(t);
return data;
}

int isEmptyBucket(Bucket* bucket){return bucket->size == 0;}

void clearBucket(Bucket *bucket)
{
while(!isEmptyBucket(bucket))dequeueBucket(bucket);
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
Bucket bucket;
initBucket(&bucket);
printf("initialised\n");
for(i=0;i<n;i++)
{
sortedInsert(&bucket,a[i]);
printf("inserted %d\n",a[i]);
}
while(!isEmptyBucket(&bucket))
{
printf("%d ", dequeueBucket(&bucket));
}
clearBucket(&bucket);
free(a);
return 0;
}