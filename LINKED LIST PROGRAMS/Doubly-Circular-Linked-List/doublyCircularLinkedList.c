#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};
void insertAtB(int x);
void deleteAtB();
void insertAtE(int x);
void deleteAtE();
void insertAtSPos(int x, int p);
void deleteAtSPos(int p);
// void insertAfterSData(int x, int x2);
void deleteAtSData(int x);
void showAll();
// int searchData(int x);
void showAllRev();
int countNodes();
struct Node* createNode()
{
	return (struct Node*)malloc(sizeof(struct Node));
}

struct Node *start = NULL;
struct Node *end = NULL;

int main()
{
	int data, data2, pos, pos2, c=-1;
	struct Node *temp;
	while(c)
	{
		//MAIN LINKED LIST CODE :
		printf("\nDoubly Linked List\n");
		//Operations Available:
		printf("0. Exit\n");
		printf("1. Show All Data\n");
		printf("2. Insert At Beginning\n");
		printf("3. Insert At Ending\n");
		printf("4. Insert Node at Specific Position \n");
		printf("5. Delete At Beginning\n");
		printf("6. Delete At Ending\n");
		printf("7. Delete At Specific Position\n");
		printf("8. Delete At Specific Data\n");
		printf("9. Traverse In Reverse Order\n");
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
				printf("Enter Data : ");
				scanf("%d",&data);
				insertAtB(data);
				break;
			case 3:
				printf("Enter Data : ");
				scanf("%d",&data);
				insertAtE(data);
				break;
			case 4:
				printf("Enter Data : ");
				scanf("%d",&data);
				printf("Enter Position : ");
				scanf("%d",&pos);
				insertAtSPos(data,pos);
				break;
			case 5:
				deleteAtB();
				break;
			case 6:
				deleteAtE();
				break;
			case 7:
				printf("Enter Position : ");
				scanf("%d",&pos);
				deleteAtSPos(pos);
				break;
			case 8:
				printf("Enter Data : ");
				scanf("%d",&data);
				deleteAtSData(data);
				break;
			case 9:
				showAllRev();
				break;
		}
	}
}

void insertAtB(int x)
{
	struct Node* temp = createNode();
	temp->data = x;
	if(start == NULL)
	{
		start = end = temp->next = temp->prev = temp;
		return;
	}
	temp->next = start;
	temp->prev = end;
	start->prev = temp;
	start = end->next = temp;
}

void showAll()
{
	struct Node* temp = start;
	if(temp == NULL)
	{
		printf("List is empty\n");
		return;
	}
	do{
		printf("%d ",temp->data);
		temp = temp->next;
	}while(temp != start);
	printf("\n");
}

void insertAtE(int x)
{
	if(start == NULL)
	{
		insertAtB(x);
		return;
	}
	struct Node* temp = createNode();
	temp -> data = x;
	temp -> next =start;
	temp -> prev = end;
	end -> next = temp;
	start -> prev = temp;
	end = temp;
	
}

void showAllRev()
{
	struct Node* temp = end;
	if(temp == NULL)
	{
		printf("List is empty\n");
		return;
	}
	do{
		printf("%d ", temp->data);
		temp = temp->prev;		
	}while(temp != end);
	printf("\n");
}

int countNodes()
{
	if(start == NULL)
		return 0;
	struct Node* temp = start;
	int i = 0;
	do
	{
		i++;
		temp = temp->next;
	}while(temp!=start);
	return i;
}
void insertAtSPos(int x, int p)
{
	if(p == 1)
	{
		insertAtB(x);
		return;
	}
	int n = countNodes();
	struct Node* temp = createNode();
	struct Node* temp2 = start;
	if(p>1 && p<=n)
	{
		for(int i = 2; i<p; i++)
		{
			temp2 = temp2->next;
		}
		temp->data = x;
		temp->next = temp2->next;
		temp->prev = temp2;
		
		temp2->next->prev = temp;
		temp2->next = temp;
	}
	else if(p == n+1)
	{
		insertAtE(x);
	}
	else
	{
		printf("Invalid Position\n");
	}
}

void deleteAtB()
{
	if(start == NULL)return;
	if(start == end)
	{
		free(start);
		end = start = NULL;
		return;
	}
	struct Node* temp = start;
	start = start->next;
	start->prev = end;
	end->next = start;
	free(temp);
}

void deleteAtE()
{
	if(start == NULL)return;
	if(start == end)
	{
		free(start);
		end = start = NULL;
		return;
	}
	struct Node* temp = end;
	end = end->prev;
	end->next = start;
	start->prev = end;
	free(temp);
}

void deleteAtSPos(int p)
{
	if(p == 1)
	{
		deleteAtB();
		return;
	}
	int n = countNodes();
	struct Node* temp = start;
	struct Node* temp2;
	if(p>1 && p<n)
	{
		for(int i = 2; i<p; i++)
		{
			temp = temp->next;
		}
		temp2 = temp->next;
		temp2->next->prev = temp;
		temp->next = temp2->next;
		free(temp2);
	}
	else if(p == n)
	{
		deleteAtE();
	}
	else
	{
		printf("Invalid Position\n");
	}
}

void deleteAtSData(int x)
{
	if(start == NULL)return;
	else
	{
		struct Node* temp = start;
		int i = 1;
		do{
			if(x == temp->data)
			{
				deleteAtSPos(i);
				return;
			}
			i++;
			temp = temp->next;
		}while(temp != start);
	}		
}