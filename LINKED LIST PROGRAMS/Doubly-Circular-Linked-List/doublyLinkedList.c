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
int searchData(int x);
void showAllRev();
struct Node* createNode()
{
	return (struct Node*)maollc(sizeof(struct Node));
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
		printf("8. Traverse In Reverse Order\n");
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
				insertAtEnd(data);
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
				deleteAtEnd();
				break;
			case 7:
				printf("Enter Position : ");
				scanf("%d",&pos);
				deleteAtSPos(pos);
				break;
			case 8:
				showAllRev();
				break;
		}
	}
}

