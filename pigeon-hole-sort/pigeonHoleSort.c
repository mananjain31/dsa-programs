#include<stdio.h>
#include<stdlib.h>
//queue implementation starts
typedef struct __queue_node
{
int data;
struct __queue_node* next;
}QueueNode;

typedef struct __queue
{
QueueNode* start;
QueueNode* end;
int size;
}Queue;

void initQueue(Queue* queue)
{
queue->start = NULL;
queue->end = NULL;
queue->size = 0;
}

int isQueueEmpty(Queue *queue)
{
return queue->size == 0;
}

void addToQueue(Queue* queue, int data)
{
QueueNode* t = (QueueNode*)malloc(sizeof(QueueNode));
t->data = data;
t->next = NULL;
if(queue->start == NULL)
{
queue->start = queue->end = t;
}
else
{
queue->end->next = t;
queue->end = t;
}
queue->size++;
}

int removeFromQueue(Queue* queue)
{
int data;
QueueNode* t;
data = queue->start->data;
t = queue->start;
queue->start = queue->start->next;
free(t);
queue->size--;
return data;
}

void clearQueue(Queue* queue)
{
QueueNode* t;
while(queue->start != NULL)
{
t = queue->start;
queue->start = queue->start->next;
free(t);
}
queue->end = NULL;
queue->size = 0;
}
//queue implementation ends

void pigeonHoleSort(int *a, int si, int ei)
{
	int i,j,min,max;
	min = max = a[0];
	for(i=si;i<=ei;i++)
	{
		if(a[i]<min)min = a[i];
		if(a[i]>max)max = a[i];
	}
	int n = (max-min)+ 1;
	Queue* queues = (Queue*)malloc(sizeof(Queue)*n);
	for(i=0;i<n;i++)initQueue(&queues[i]);
	for(i=si;i<=ei;i++)
	{
		j = a[i] - min;
		addToQueue(&queues[j],a[i]);
	}
	j=0;
	for(i=0;i<n;i++)
	{
		while(!isQueueEmpty(&queues[i]))
		{
			a[j] = removeFromQueue(&queues[i]);
			j++;
		}
	}
	for(i=0;i<n;i++)clearQueue(&queues[i]);
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
	pigeonHoleSort(a,0,n-1);
	for(i=0;i<n;i++)printf("%d\n",*(a+i));
	free(a);
	return 0;
}