#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

void enqueue();
void dequeue();
void showAll();

int front = -1;
int rear = -1;
int queue[MAX];

int main()
{
	while(1)
	{
		int ch;
		printf("\n......MENU......\n");
		printf("1. Enqueue \n");
		printf("2. Dequeue \n");
		printf("3. Show All \n");
		printf("4. Exit \n");
		printf("Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				showAll();
				break;
			case 4:
				exit(0);
		}
	}
	return 1;
}

void enqueue()
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		int x;
		printf("Enter Any Data : ");
		scanf("%d",&x);
		if(front == -1) front++;
		rear++;
		queue[rear] = x;
	}
}

void dequeue()
{
	if(rear == -1 || front > rear)
		printf("Queue Empty\n");
	else front++;
}

void showAll()
{
	if(rear == -1 || front > rear)
		printf("Queue Empty\n");
	else
	{
		for(int i = front; i <= rear; i++)
			printf("%d ",queue[i]);
		printf("\n");
	}
}
