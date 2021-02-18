#include<stdio.h>
#include<stdbool.h>
#define CAPACITY 5
void push();
int pop();
int peek();
bool empty();
int main()
{
	int a[CAPACITY];
	int c = 1;
	while(c)
	{
		printf("STACK USING ARRAY\n");
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
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		
		}
	}
}