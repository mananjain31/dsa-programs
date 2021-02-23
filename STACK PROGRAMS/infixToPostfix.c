#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define CAPACITY 1000
char stack[CAPACITY];
char pop();
char peek();
void push(char);
bool empty();
int priority(char);
int top = -1;

void main ()
{
	int i, k = 0;
	char input[CAPACITY];
	char output[CAPACITY];
	printf("Enter Expression : ");
	scanf("%s",input);
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
			output[k++] = input[i];
		else if (input[i] == ')' || input[i] == '(')
		{
			if (input[i] == '(') push(input[i]);
			else if (input[i] == ')')
			{
				while (peek() != '(')
					output[k++] = pop();
				pop();
			}
		}
		else 
		{
			while (priority(input[i]) <= priority(peek()) && peek() != '(')
			{
				output[k++] = pop();
			}
			push(input[i]);
		}

	}
	output[k] = '\0';
	printf("%s", output);
}

void push(char x)
{
	stack[++top] = x;
}

char pop()
{
	return stack[top--];
}

char peek()
{
	return stack[top];
}

bool empty()
{
	return (top == -1 ? true : false);
}

int priority(char x)
{
	if(x == '+' || x == '-')return 1;
	if(x == '*' || x == '/')return 2;
	if(x == '^')return 3;
}