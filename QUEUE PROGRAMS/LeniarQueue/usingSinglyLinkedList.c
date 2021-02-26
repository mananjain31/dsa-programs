#include<stdio.h>
#include<stdlib.h>
struct Node 
{
	int data;
	struct Node* next;
};

void enqueue();
void dequeue();
void showAll();

struct Node* front = NULL;
struct Node* rear = NULL;

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
	return 0;
}

void enqueue()
{
	struct Node* temp=malloc(sizeof(struct Node));
	int x;
	printf("Enter Any Data : ");
	scanf("%d", &x);
	temp->data = x;
	if(rear == NULL)
	{
		rear = temp;
		front = temp;
	} 
	else 
	{
		rear->next=temp;
		rear = temp;
	}
	temp->next  = NULL;
}

void dequeue()
{
	if(front == NULL && rear == NULL)
	{
		printf("Queue Empty\n");
	}
	else if(front == rear)
	{
		free(front);
		front = rear = NULL;
	}
	else
	{
		struct Node* temp = front;
		front = front->next;
		free(temp);
	}
}

void showAll()
{
	if(front == NULL && rear == NULL)
	{
		printf("Queue Empty\n");
	}
	else 
	{
		for(struct Node* i = front; i!=NULL; i=i->next)
		{
			printf("%d ", i->data);
		}
		printf("\n");
	}
}
