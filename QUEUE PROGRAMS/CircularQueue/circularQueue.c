#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void enqueue();
void dequeue();
void showAll();

int queue[MAX];
int front = -1;
int rear = -1;

int main()
{
	while(1)
	{
		printf("\n...CIRCUALR QUEUE...\n");
		printf("1. enqueue\n");
		printf("2. dequeue\n");
		printf("3. Show All\n");
		printf("4. Exit\n");
		printf("Enter your choice : ");
		int ch;
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
				break;
		}
	}
	return 0;
}

