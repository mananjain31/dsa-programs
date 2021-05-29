#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct __stack_node
{
	void* data;
	struct __stack_node* next;	
}StackNode;

typedef struct _satck 
{
	int elementSize;
	struct __stack_node* top;	
	int size;
}Stack;

void initStack(Stack* stack, int elementSize)
{
	stack->top = NULL;
	stack->size = 0;
	stack->elementSize = elementSize;
}
void push(Stack* stack,const void* data)
{
	StackNode* t = (void*)malloc(sizeof(StackNode)); 
	t->data = (void*)malloc(stack->elementSize);
	memcpy(t->data,data, stack->elementSize);
	t->next = stack->top;
	stack->top = t;
	stack->size++; 
}

void pop(Stack* stack, void* data)
{
	memcpy(data,stack->top->data,stack->elementSize);
	free(stack->top->data);
	SatckNode t = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	free(t);
}

int isEmpty(Stack* stack)
{
	return stack->top == NULL;
	//or
	//return stack->size == 0;
}
	
///////////////////////////////////////////////////////
int main()
{
	int x;
	Stack s;
	initStack(&s, sizeof(int));
	x = 24;
	push(&s, (const void*)&x);
	x = 90;
	push(&s, &x);
	while(!isEmpty(&s))
	{
		pop(&s, (void*)&x);
		printf("%d ",x);
	}
	return 0;
}	