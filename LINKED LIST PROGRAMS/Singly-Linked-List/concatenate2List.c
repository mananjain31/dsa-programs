#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	int data;
	struct Node *next;
};	

struct Node* insertAtB(int x, struct Node *start)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = start;
	start = temp;
}
 
void showAll(struct Node *start)
{
	struct Node *temp = start;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

struct Node* concatenate(struct Node *start1, struct Node *start2)
{
	if(start1 == NULL ) return start2;
	struct Node *temp = start1;
	while(temp -> next != NULL) temp = temp -> next;
	temp -> next = start2;
	return start1;
}

int main()
{
	struct Node *start1 = NULL;
	struct Node *start2 = NULL;
	start1 = insertAtB(10, start1);
	start1 = insertAtB(20, start1);
	start2 = insertAtB(44, start2);
	start2 = insertAtB(55, start2);
	showAll(start1);
	showAll(start2);
	start1 = concatenate(start1,start2);
	showAll(start1);
	return 0;
}