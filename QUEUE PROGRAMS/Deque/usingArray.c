#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

void insertAtB();
void insertAtE();
void deleteAtB();
void deleteAtE();
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
		printf("1. insertAtB \n");
		printf("2. insertAtE\n");
		printf("3. deleteAtB\n");
		printf("4. deleteAtE\n");
		printf("5. Show All \n");
		printf("6. Exit \n");
		printf("Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertAtB();
				break;
			case 2:
				insertAtE();
				break;
			case 3:
				deleteAtB();
				break;
			case 4:
				deleteAtE();
				break;
			case 5:
				showAll();
				break;
			case 6:
				exit(0);
		}
	}
	return 1;
}

void insertAtE()
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

void insertAtB()
{
	if(front == 0)
		printf("Queue Overflow\n");
	else
	{
		int x;
		printf("Enter Any Data : ");
		scanf("%d",&x);
		if(front == -1) 
		{
			front++;
			rear++;
		}
		else front--;
		queue[front] = x;
	}
}

void deleteAtB()
{
	if(rear == -1 || front > rear)
		printf("Queue Empty\n");
	else front++;
}

void deleteAtE()
{
	if(rear == -1 || front > rear)
		printf("Queue Empty\n");
	else rear--;
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
