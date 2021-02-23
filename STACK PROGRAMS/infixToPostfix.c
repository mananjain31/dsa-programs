#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
char stack[1000];
char pop();
char peek();
void push();
bool empty();

void main()
{
	int i, k = 0;
	char input[1000];
	char output[1000];
	printf("Enter Expression : ");
	scanf("%s",input);
	for(i = 0; input[i] != '\0'; i++)
	{
		if(input[i] >= 'A' && input[i] <= 'Z')
		{
			output[k++] = input[i];
		}
		else 
		{
			//will be continued
		}
	}
}