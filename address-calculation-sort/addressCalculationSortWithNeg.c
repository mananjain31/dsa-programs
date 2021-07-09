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
int negpos,pos,len,i,j,key,min,max;
Bucket buckets[10];
Bucket negbuckets[10];
max = a[si];
min = a[si];
for(i=si;i<=ei;i++) 
{
if(max<a[i]) max = a[i];
if(min>a[i]) min = a[i];
}
if(min == max) return;
for(i=0;i<10;i++)initBucket(&buckets[i]);
if(min < 0) for(i=0;i<10;i++)initBucket(&negbuckets[i]);
pos = 1;
while(max/pos != 0) pos*=10;
pos = pos/10;
if(min < 0)
{
negpos = 1;
while(min/negpos != 0) negpos*=10;
negpos = negpos/10;
}
//inserting values into the buckets
for(i=si;i<=ei;i++)
{
if(a[i]<0)
{
key = -1*(hash(a[i],negpos)); // for getting the key positive
sortedInsert(&negbuckets[9-key],a[i]); // for order preservance
}
else
{
key = hash(a[i],pos);
sortedInsert(&buckets[key],a[i]);
}
}
j=si;
if(min < 0)
{
for(i=0;i<10;i++)
{
while(!isEmptyBucket(&negbuckets[i]))
{
a[j] = dequeueBucket(&negbuckets[i]);
j++;
}
}
}

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
printf("Enter Collection size -> ");
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