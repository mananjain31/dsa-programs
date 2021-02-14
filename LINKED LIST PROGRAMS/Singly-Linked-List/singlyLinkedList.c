#include<stdio.h>
#include<stdlib.h>
void insertAtB(int x);
void insertAtEnd(int x);
void insertAtSPos(int x, int p);
//void insertAfterSData(int x, int p);
int countNodes();
void showAll();
struct Node
{
	int data;
	struct Node *next;
};
struct Node *start = NULL;
int main()
{
	int data, pos, c=-1;
	while(c)
	{
		//MAIN LINKED LIST CODE :
		printf("\nSingly Linked List\n");
		//Operations Available:
		printf("0. Exit\n");
		printf("1. Show All Data\n");
		printf("2. Count Nodes\n");
		printf("3. Insert At Beginning\n");
		printf("4. Insert At Ending\n");
		printf("5. Insert Node at Specific Position \n");
		printf("Enter Your Choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				showAll();
				break;
			case 2:
				printf("No. of nodes: %d\n",countNodes());
				break;
			case 3:
				printf("Enter Data : ");
				scanf("%d",&data);
				insertAtB(data);
				break;
			case 4:
				printf("Enter Data : ");
				scanf("%d",&data);
				insertAtEnd(data);
				break;
			case 5:
				printf("Enter Data : ");
				scanf("%d",&data);
				printf("Enter Position : ");
				scanf("%d",&pos);
				insertAtSPos(data, pos);
				break;
		}
	}
	return 0;
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
int countNodes()
{
	int i=0;
	struct Node *temp = start;
	while(temp!=NULL)
	{
		i++;
		temp = temp -> next;
	}
	return i;
}
void insertAtB(int x)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = start;
	start = temp;
}
void insertAtEnd(int x)
{
	if(start == NULL)
	{
		insertAtB(x);
		return;
	}
	struct Node *temp = start;
	while(temp -> next!=NULL)
	{
		temp = temp -> next;
	}
	struct Node *temp2 = (struct Node*)malloc(sizeof(struct Node));
	temp2 -> data = x;
	temp2 -> next = NULL;
	temp -> next = temp2;
}

void insertAtSPos(int x,int p)
{
	if(p == 1)
	{
		insertAtB(x);
	}
	else if(p == countNodes() + 1)
	{
		insertAtEnd(x);		
	}
	else if(p > 1 && p <= countNodes())
	{
		struct Node *temp = start;
		struct Node *temp2 = (struct Node*) malloc(sizeof(struct Node*));
		for(int i = 1; i < p - 1; i++)
		{
			temp = temp -> next;
		}
		temp2 -> data = x;
		temp2 -> next = temp -> next; 
		temp -> next = temp2;
	}
	else
	{
		printf("Invalid Position\n");
	}
}
