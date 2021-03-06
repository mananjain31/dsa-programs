#include<stdio.h>
#include<stdlib.h>
//bucket implementation starts
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
//bucket implementation ends


int hash(int value, int pos)//order preserving
{
int key;
key = value / pos;
return key;
}

void addressCalculationSort(int *a, int si, int ei)
{
int pos,max,i,j,key;
Bucket buckets[10];
max = a[si];
for(i=si;i<=ei;i++) if(max<a[i]) max = a[i];
if(max == 0)return;
for(i=0;i<10;i++)initBucket(&buckets[i]);
pos = 1;
while(max/pos != 0) pos*=10;
pos = pos/10;
//inserting values into the buckets
for(i=si;i<=ei;i++)
{
key = hash(a[i],pos);
sortedInsert(&buckets[key],a[i]);
}
j=0;
for(i=0;i<10;i++)
{
while(!isEmptyBucket(&buckets[i]))
{
a[j] = dequeueBucket(&buckets[i]);
j++;
}
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
addressCalculationSort(a,0,n-1);
for(i=0;i<n;i++)printf("%d\n",*(a+i));
free(a);
return 0;
}