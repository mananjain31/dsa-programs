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
void insertAtEnd(int x);
void deleteAtEnd();
void insertAtSPos(int x, int p);
void deleteAtSPos(int p);
void insertAfterSData(int x, int x2);
void deleteAtSData(int x);
void showAll();
int countNodes();
int searchData(int x);
void showAllRev();
void bubbleSort();
void swapData(struct Node *a, struct Node *b);
void removeDupliSorted();
void removeDupliUnSorted();

struct Node* getNode(int p);


struct Node *start = NULL;

int main()
{
	int data, data2, pos, pos2, c=-1;
	while(c)
	{
		//MAIN LINKED LIST CODE :
		printf("\nDoubly Linked List\n");
		//Operations Available:
		printf("0. Exit\n");
		printf("1. Count Nodes\n");
		printf("2. Show All Data\n");
		printf("3. Search Data \n");
		printf("4. Insert At Beginning\n");
		printf("5. Insert At Ending\n");
		printf("6. Insert Node at Specific Position \n");
		printf("8. Delete At Beginning\n");
		printf("9. Delete At Ending\n");
		printf("10. Delete At Specific Position\n");
		printf("15. Traverse In Reverse Order\n");
		printf("16. Bubble Sort \n");
		printf("20. Sort and Remove Duplicate data\n");
		printf("21. Remove Duplicate data Without Sorting\n");

		printf("Enter Your Choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				printf("No. of nodes: %d\n",countNodes());
				break;
			case 2:
				showAll();
				break;
			case 3:
				printf("Enter Data To Search : ");
				scanf("%d",&data);
				int index = searchData(data);
				if(index == -1) printf("Data not Found\n");
				else printf("Data found at Index : %d\n",index);
				break;
			case 4:
				printf("Enter Data : ");
				scanf("%d",&data);
				insertAtB(data);
				break;
			case 5:
				printf("Enter Data : ");
				scanf("%d",&data);
				insertAtEnd(data);
				break;
			case 6:
				printf("Enter Data : ");
				scanf("%d",&data);
				printf("Enter Position : ");
				scanf("%d",&pos);
				insertAtSPos(data, pos);
				break;
			case 8:
				deleteAtB();
				break;
			case 9:
				deleteAtEnd();
				break;
			case 10:
				printf("Enter Position : ");
				scanf("%d",&pos);
				deleteAtSPos(pos);
				break;
			case 15:
				showAllRev();
				break;
			case 16:
				bubbleSort();
				break;
			case 20:
				removeDupliSorted();
				break;
			case 21:
				removeDupliUnSorted();
				break;
		}
	}
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
	temp->prev = NULL;
	temp->data = x;
	temp->next = start;
	if(start!=NULL)
		start->prev = temp;
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
	temp2 -> prev = temp;
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
		for(int i = 1; i < p -1 ; i++)
		{
			temp = temp -> next;
		}
		temp2 -> data = x;
		temp2 -> next = temp -> next; 
		temp -> next -> prev =temp2;
		temp2 -> prev =  temp;
		temp -> next = temp2;
	}
	else
	{
		printf("Invalid Position\n");
	}
}

void insertAfterSData(int x, int x2)
{
	if(start  == NULL)
	{
		printf("List Empty\n");
		return;
	}
	struct Node *temp = start;
	while(temp != NULL)
	{
		if(temp -> data  == x2)
		{
			struct Node *temp2 = (struct Node*) malloc(sizeof(struct Node));
			temp2 -> data = x;
			temp2 -> next = temp -> next;
			temp -> next = temp2;
			return;
		}
		temp = temp -> next;
	}
	printf("Given data not found\n");
}

int searchData(int x)
{
	int i = -1;
	struct Node *temp = start;
	while(temp != NULL)
	{
		i++;
		if(temp -> data == x)return i;
		temp = temp -> next;
	}
	return -1;
}

void deleteAtB()
{
	if(start == NULL) return;
	struct Node* temp = start;
	start = start -> next;
	free(temp);
	start -> prev = NULL;
}

void deleteAtEnd()
{
	if(start == NULL) return;
	struct Node *temp = start;
	if(start -> next == NULL)
	{
		deleteAtB();
		return;
	}		
	while(temp -> next -> next!= NULL)
	{
		temp = temp -> next;
	}
	free(temp -> next);
	temp -> next = NULL;
}

void deleteAtSPos(int p)
{
	if(p == 1)
	{
		deleteAtB();
		return;
	}
	if(p == countNodes())
	{
		deleteAtEnd();
		return;
	}
	if(p > 1 && p < countNodes())
	{
		struct Node *temp = start;
		for(int i = 1; i < p - 1; i++)
		{
			temp = temp -> next;
		}
		struct Node *temp2 = temp -> next;
		temp -> next -> next -> prev = temp;
		temp -> next = temp -> next -> next;
		free(temp2);
	}
	else
	{
		printf("Invalid Position\n");
	}
}


void showAllRev()
{
	if(start == NULL)return;
	struct Node* temp = start;
	while(temp->next != NULL)
	{
		temp = temp ->next;
	}
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp -> prev;
	}
	printf("\n");
}


void removeDupliSorted()
{
	bubbleSort();
	int n = countNodes();
	printf("%d\n",n);
	if(start == NULL || start -> next == NULL) return;
	struct Node *temp = start;
	for(int i = 1; i < n;)
	{
		if(temp->data == temp->next->data)
		{
			deleteAtSPos(i+1);
			showAll();
			n--;
		}
		else
		{
			temp = temp -> next;
			i++;
		}
	}
}

void bubbleSort()
{
	if(start == NULL || start->next == NULL) return;
	struct Node *temp = start;
	int n = countNodes();
	showAll();
	for(int i = 1; i < n ; i++)
	{
		temp = start;
		for(int j = i; j < n; j++)
		{	
			if(temp->data > temp->next->data)
			{
				swapData(temp, temp->next);
			}
			temp = temp -> next;
		}
		showAll();
	}
}

void swapData(struct Node *a, struct Node *b)
{
	int t = a->data;
	a->data = b->data;
	b->data = t;	
}

void removeDupliUnSorted()
{
	int n = countNodes();
	printf("%d\n",n);
	if(start == NULL || start -> next == NULL) return;
	struct Node *temp ;
	struct Node *temp2 ;
	for(int j = 1; j < n; j++)	
	{
		temp = getNode(j);
		temp2 = getNode(j);
		for(int i = j; i < n;)
		{
			if(temp2 -> next -> data == temp -> data) 
			{
				deleteAtSPos(i+1);
				n--;
			}
			else
			{
				temp2 = temp2-> next; 
				i++;
			}
		}
	}
}

struct Node* getNode(int p)
{
	int n = countNodes();
	if(p>n) return NULL;
	struct Node *temp = start;
	for(int i = 1 ; i < p; i++)
	{
		temp = temp -> next;
	}
	return temp;
}