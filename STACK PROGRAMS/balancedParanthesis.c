#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define CAPACITY 1000
void push();
int pop();
int peek();
bool empty();
int top = -1;
int a[CAPACITY];
int main()
{
	char data[1000];
	printf("Enter Expression: ");
	scanf("%s",&data);
	for(int i = 0; data[i] != '\0'; i++)
	{
		if(data[i] == '{' || data[i] == '(' || data[i] == '[')
		{
			push(data[i]);
		}
		else if(data[i] == '}' || data[i] == ')' || data[i] == ']')
		{
			if(top == -1)
			{
				top = 1;
				break;
			}
			if(data[i] == '}')
			{
				if(peek() == '{') pop();
				else break;
			}
			if(data[i] == ')')
			{
				if(peek() == '(') pop();
				else break;
			}
			if(data[i] == ']')
			{
				if(peek() == '[') pop();
				else break;
			}
		}
	}
	if(empty()) printf("Correct...\n");
	else printf("Incorrect...\n");
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
