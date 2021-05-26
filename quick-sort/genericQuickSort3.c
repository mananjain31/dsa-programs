#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
/*
struct Node
{
	int lb, ub;
	struct Node* next;
};
*/
typedef struct __stack_node
{
	int data;
	struct __stack_node *next;
}StackNode;

typedef struct _stack 
{
	struct __stack_node *top;
	int size;
}Stack;
//struct Node* top;
void push(Stack *stack, int data)
{
	// struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	// t->lb = lb;
	// t->ub = ub;
	// t->next = top;
	// top = t;
	StackNode *t =(StackNode*)malloc(sizeof(StackNode)); 
	t->data = data;
	t->next = stack->top;
	stack->top = t;
	stack->size++;
}
int pop(Stack* stack)
{
	// struct Node* t = top;
	// *lb = t->lb;
	// *ub = t->ub;
	// top=top->next;
	// free(t);
	int data = stack->top->data;
	StackNode* t = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	free(t);
	return data;
}
int isEmpty(Stack* stack)
{
	return (stack->top == NULL);
}
void swap(void *i, void *j, int es)
{
	void* block = malloc(es);
	memcpy(block,(const void*)i,es);
	memcpy(i,(const void*)j,es);
	memcpy(j,(const void*)block,es);
	free(block);
}
int init(Stack* stack)
{
	stack->top = NULL;
	stack->size = 0;
}
void quickSort(void *a, int lb, int ub, int es, int (*p2f)(void*, void*))
{
	int e,f;
	Stack *lbStack = (Stack*)malloc(sizeof(Stack));
	Stack *ubStack = (Stack*)malloc(sizeof(Stack));
	init(lbStack);
	init(ubStack);
	push(lbStack, lb);
	push(ubStack, ub);
	while(!isEmpty(lbStack) || !isEmpty(ubStack) )
	{	
		//pop
		e = lb = pop(lbStack);
		f = ub = pop(ubStack);
		while(e<f)
		{
			// while(e<ub && a[e] <= a[lb]) e++;
			while( e<ub && p2f((a+(es*e)), (a+(es*lb))) <= 0 ) e++;
			// while(a[f] > a[lb]) f--;
			while( p2f((a+(es*f)), (a+(es*lb))) > 0) f--;
			if(e < f) swap(a+es*e, a+es*f, es);
			else swap(a+es*lb,a+es*f, es);
		}
		if(f+1 < ub)
		{
			// push(f+1, ub);
			push(lbStack, f+1);
			push(ubStack, ub);
		}
		if(f-1 > lb)
		{
			// push(lb, f-1);
			push(lbStack, lb);
			push(ubStack, f-1);		
		}
	}
	free(lbStack);
	free(ubStack);
}

///////////////////////////////
struct student
{
	int id;
	char name[20];	
};
int mycomparator(void* i, void* j)
{
	struct student* l = (struct student*)i;
	struct student* r = (struct student*)j;
	
	return strcmp(l->name, r->name); ////////////may cause error
}
int main()
{
	//top = NULL;
	int n;
	struct student *a;
	printf("Enter Requirement : ");
	scanf("%d",&n);
	a = (struct student*)malloc(sizeof(struct student)*n);
	for(int i=0;i<n;i++) 
	{
		printf("Enter id : ");
		scanf("%d", &a[i].id);
		printf("now Enter name : ");
		scanf("%s", a[i].name);
	}
	quickSort(a,0,n-1,sizeof(struct student),mycomparator);
	for(int i=0;i<n;i++)	printf("%d %s\n", a[i].id, a[i].name);
	free(a);
	return 0;
}
