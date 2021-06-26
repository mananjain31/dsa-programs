#include<stdio.h>
#include<stdlib.h>
//////////////////queue implementation starts/////////////

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

//////////////////queue implementation ends/////////////

int main()
{
int *x;
int n,i,j,k,m,len,max,min;
Queue queue[10];
printf("Enter No. of Elements : ");
scanf("%d", &n);
x = malloc(sizeof(int)*n);
for(i=0;i<10;i++) initQueue(&queue[i]);
for(i=0;i<n;i++)
{
printf("Enter a Number : ");
scanf("%d", &x[i]);
}
min = x[0];
for(i=1;i<n;i++) if(x[i]<min) min = x[i];
for(i=0;i<n;i++) x[i] -= min;
max = x[0];
for(i=1;i<n;i++) if(x[i]>max) max = x[i];
len = 1;
while(len <= max) len*=10;

for(i=1; i<=len; i*=10)
{
for(j=0;j<n;j++)
{
k = x[j]/i;
k = k%10;
addToQueue(&queue[k],x[j]);
}
k = 0;
for(m=0;m<10;m++)
{
while(!isQueueEmpty(&queue[m]))
{
x[k++] = removeFromQueue(&queue[m]);
}
}
}
for(i=0;i<n;i++) x[i] += min;
for(i=0;i<n;i++) clearQueue(&queue[i]);
for(i=0;i<n;i++) printf("%d\n", x[i]);;
free(x);
return 0;
}