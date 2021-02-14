#include<stdio.h>
#include<stdlib.h>
void insertAtB(int x);
void showAll();
struct Node
{
	int data;
	struct Node *next;
};
struct Node *start = NULL;
int main()
{
	int run = 1;
	int data, c=-1;
	while(c)
	{
		//MAIN LINKED LIST CODE :
		printf("\nSingly Linked List\n");
		//Operations Available:
		printf("0. Exit\n");
		printf("1. Insert At Beginning\n");
		printf("2. Show All Data\n");
		printf("Enter Your Choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter Data: ");
				scanf("%d",&data);
				insertAtB(data);
				break;
			case 2:
				showAll();
				break;
			case 0:
				break;
		}
	}
	return 0;
}
void insertAtB(int x)
{
	struct Node *temp = malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = start;
	start = temp;
}
void showAll()
{
	struct Node *temp = start;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}