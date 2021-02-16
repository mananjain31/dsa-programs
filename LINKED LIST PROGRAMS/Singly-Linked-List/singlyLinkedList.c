#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	int data;
	struct Node *next;
};
void insertAtB(int x);
void deleteAtB();
void insertAtEnd(int x);
void deleteAtEnd();
void insertAtSPos(int x, int p);
void deleteAtSPos(int p);
void insertAfterSData(int x, int x2);
void deleteAtSData(int x);
void updateSData(int x, int x1);
int searchData(int x);
int countNodes();
void findMinMaxVal();
void showAll();
void reverseList();
void showAllRev();
void bubbleSort();
void swapData(struct Node*, struct Node*);
void showRev(struct Node*);
bool checkPallindrome();
struct Node *start = NULL;
int main()
{
	int data, data2, pos, c=-1;
	while(c)
	{
		//MAIN LINKED LIST CODE :
		printf("\nSingly Linked List\n");
		//Operations Available:
		printf("0. Exit\n");
		printf("1. Count Nodes\n");
		printf("2. Show All Data\n");
		printf("3. Search Data \n");
		printf("4. Insert At Beginning\n");
		printf("5. Insert At Ending\n");
		printf("6. Insert Node at Specific Position \n");
		printf("7. Insert Node after Specific Data \n");
		printf("8. Delete At Beginning\n");
		printf("9. Delete At Ending\n");
		printf("10. Delete At Specific Position\n");
		printf("11. Delete Node Having Specific Data\n");
		printf("12. Update Specific Data\n");
		printf("13. Find Minimum and Maximum Value\n");
		printf("14. Reverse List\n");
		printf("15. Traverse In Reverse Order\n");
		printf("16. Bubble Sort \n");
		printf("17. Check Pallindrome\n");
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
			case 7:
				printf("Enter Data after which to insert : ");
				scanf("%d",&data2);
				printf("Enter Data To insert : ");
				scanf("%d",&data);
				insertAfterSData(data, data2);
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
			case 11:
				printf("Enter Data : ");
				scanf("%d",&data);
				deleteAtSData(data);
				break;
			case 12:
				printf("Enter Data which need to be updated : ");
				scanf("%d",&data);
				printf("Enter Updated Data : ");
				scanf("%d",&data2);
				updateSData(data, data2);
				break;
			case 13:
				findMinMaxVal();
				break;
			case 14:
				reverseList();
				break;
			case 15:
				showAllRev();
				break;
			case 16:
				bubbleSort();
				break;
			case 17:;
				if(checkPallindrome())printf("The List is Pallindrome\n");
				else printf("The List is not Pallindrome\n");
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
		for(int i = 1; i < p -1 ; i++)
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
		temp -> next = temp -> next -> next;
		free(temp2);
	}
	else
	{
		printf("Invalid Position\n");
	}
}

void deleteAtSData(int x)
{
	if(start == NULL)return;
	if(start -> data == x)
	{
		deleteAtB();
		return;
	}
	struct Node* temp = start;
	while(temp -> next != NULL)
	{
		if(temp -> next -> data == x)
		{
			struct Node *temp2 = temp -> next;
			temp -> next = temp -> next -> next;
			free(temp2);
			return;
		}
		temp = temp -> next;
	}
}

void updateSData(int x, int x1)
{
	if(start == NULL)
	{
		printf("List Empty\n");
		return;
	}
	struct Node *temp = start;
	while(temp != NULL)
	{
		if(temp -> data == x)
		{
			temp -> data = x1;
			return;
		}
		temp = temp -> next;
	}
	printf("Given data not found\n");
	return;
}

void findMinMaxVal()
{
	if(start == NULL)
	{
		printf("Empty List\n");
		return;
	}
	int min = start -> data;
	int max = start -> data;
	struct Node *temp = start;
	while(temp != NULL)
	{
		if(temp -> data < min) min = temp -> data;
		if(temp -> data > max) max = temp -> data;
		temp = temp -> next;
	}
	printf("Minimun Value is : %d\n", min);
	printf("Maximum Value is : %d\n", max);
}

void reverseList()
{
	struct Node *temp1 = NULL;
	struct Node *temp2 = start;
	struct Node *temp3;
	if(start == NULL) return;
	while(temp2 != NULL)
	{
		temp3 = temp2 -> next;
		temp2 -> next = temp1;
		temp1 = temp2;
		temp2 = temp3;
	}
	start = temp1;
}

void showAllRev()
{
	showRev(start);
	printf("\n");
}
void showRev(struct Node* temp)
{
	if(temp == NULL) return;
	showRev(temp -> next);
	printf("%d ", temp -> data);
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

bool checkPallindrome()
{
	if(start == NULL) return false;
	if(start->next == NULL) return true;
	struct Node *s1 = start;
	struct Node *b1;
	struct Node *b2 = NULL;
	int n = countNodes();
	for(int i = 1; i <= n/2; i++)
	{
		b1 = start;
		s1 = start;
		while(b1->next != b2)
		{
			b1 = b1 -> next;
		}
		b2 = b1;
		for(int j = 1; j < i; j++)
		{
			s1 = s1 -> next;
		}
		if(s1 -> data != b1 -> data) return false;
	}
	return true;
}

