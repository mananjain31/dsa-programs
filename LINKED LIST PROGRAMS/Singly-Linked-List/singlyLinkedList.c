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
void main()
{
	insertAtB(10);
	insertAtB(20);
	insertAtB(30);
	insertAtB(40);
	insertAtB(50);
	showAll();
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
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}