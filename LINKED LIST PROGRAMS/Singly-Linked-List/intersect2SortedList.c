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

struct Node* intersect(struct Node *start1, struct Node *start2)
{
	struct Node *start3 = (struct Node*)malloc(sizeof(struct Node));
	if(start1 == NULL ) return start2;
	if(start2 == NULL ) return start1;
	struct Node *temp = start3;
	struct Node *temp2=NULL;
	
	
	while(start1!=NULL && start2!=NULL)
	{
		if(start1->data < start2->data)
		{
			temp->data = start1->data;
			start1 = start1 -> next;
		}
		else
		{
			temp -> data = start2 -> data;
			start2 = start2 -> next;
		}
		temp -> next = (struct Node*)malloc(sizeof(struct Node));
		temp2 = temp;
		temp = temp -> next;
	}
	
	while(start1!=NULL)
	{
		temp->data = start1->data;
		start1 = start1 -> next;
		temp -> next = (struct Node*)malloc(sizeof(struct Node));
		temp2 = temp;
		temp = temp -> next;
	}
	while(start2!=NULL)
	{
		temp->data = start2->data;
		start2 = start2 -> next;
		temp -> next = (struct Node*)malloc(sizeof(struct Node));
		temp2 = temp;
		temp = temp -> next;
	}
	temp2->next = NULL;
	free(temp);
	return start3;
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
	struct Node *start3 = NULL;
	start1 = insertAtB(40, start1);
	start1 = insertAtB(30, start1);
	start1 = insertAtB(20, start1);
	start1 = insertAtB(10, start1);
	
	start2 = insertAtB(99, start2);
	start2 = insertAtB(66, start2);
	start2 = insertAtB(55, start2);
	start2 = insertAtB(11, start2);
	
	start3 = intersect(start1, start2);
	showAll(start1);
	showAll(start2);
	showAll(start3);
	return 0;
}