#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define CAPACITY 5
void push();
int pop();
int peek();
bool empty();
int top = -1;
int a[CAPACITY];
int main()
{
	int c = 1;
	int data;
	while(c)
	{
		printf("\nSTACK USING ARRAY\n");
		printf("0. Exit\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. peek\n");
		printf("4. check if empty\n");
		printf("Enter Your Choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				printf("Enter Data to Push : ");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				printf("Data Popped: %d\n", pop());
				break;
			case 3:
				printf("Data At Top: %d\n", peek());
				break;
			case 4:
				printf("stack is empty? Ans-> %s \n", empty()?"true":"false ");
				break;
		}
	}
}

void push(int data)
{
	if(top == CAPACITY-1)
	{
		printf("Stack Overflow\n");
		return;
	}
	top++;
	a[top] = data;
}

int peek()
{
	if(top == -1)
	{
		printf("stack empty\n");
		// exit(0);
		return -1;
	}
	return a[top];
}

int pop()
{
	if(top == -1)
	{
		printf("stack underflow\n");
		// exit(0);
		return -1;
	}
	return a[top--];
}

bool empty()
{
	if(top == -1) return true;
	return false;
}