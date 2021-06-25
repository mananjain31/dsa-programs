#include<stdio.h>
#include<stdlib.h>
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


int main()
{
int ch, data;
Queue queue;
initQueue(&queue);
while(1)
{
printf("Queue : \n");
printf("1. add\n");
printf("2. remove\n");
printf("3. isEmpty\n");
printf("4. Exit\n");
scanf("%d", &ch);
switch(ch)
{
case 1:
printf("Enter number to add to Queue: \n");
scanf("%d", &data);
addToQueue(&queue, data);
break;

case 2:
if(isQueueEmpty(&queue))
printf("Queue is Empty\n");
else
printf("Removed %d from Queue\n", removeFromQueue(&queue));
break;

case 3:
if(isQueueEmpty(&queue)) printf("Queue Empty\n");
else printf("Queue Not Empty\n");
break;

case 4:
return 0; 
break;
}
}
clearQueue(&queue);
return 0;
}