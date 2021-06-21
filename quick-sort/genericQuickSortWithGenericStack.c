#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct __stack_node
{
	void* data;
	struct __stack_node *next;
}StackNode;

typedef struct _stack 
{
	int elementSize;
	StackNode* top;
	int size;
}Stack;
//struct Node* top;
void push(Stack *stack, const void* data)
{
	// struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	// t->lb = lb;
	// t->ub = ub;
	// t->next = top;
	// top = t;
	StackNode *t =(StackNode*)malloc(sizeof(StackNode)); 
	t->data = (void*)malloc(stack->elementSize);
	memcpy(t->data, data, stack->elementSize);
	t->next = stack->top;
	stack->top = t;
	stack->size++;
}
void pop(Stack* stack, void* data)
{
	// struct Node* t = top;
	// *lb = t->lb;
	// *ub = t->ub;
	// top=top->next;
	// free(t);
	// int data = stack->top->data;
	memcpy(data, (const void*)(stack->top->data), stack->elementSize);
	StackNode* t = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	free(t->data);
	free(t);
}
int isEmpty(Stack* stack)
{
	return (stack->top == NULL);
}
void swap(void *i, void *j, int es)
{
	if(i == j) return;
	void* block = (void*)malloc(es);
	memcpy(block,(const void*)i,es);
	memcpy(i,(const void*)j,es);
	memcpy(j,(const void*)block,es);
	free(block);
}
int initStack(Stack* stack, int elementSize)
{
	stack->top = NULL;
	stack->size = 0;
	stack->elementSize = elementSize;
}
void quickSort(void *a, int lb, int ub, int es, int (*p2f)(void*, void*))
{
	int e,f;
	Stack lbStack, ubStack;
	initStack(&lbStack,es);
	initStack(&ubStack,es);
	push(&lbStack, &lb);
	push(&ubStack, &ub);
	while(!isEmpty(&lbStack) || !isEmpty(&ubStack) )
	{	
		pop(&lbStack, &lb);
		pop(&ubStack, &ub);
		//pop
		e = lb;
		f = ub;

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
			int x;
			// push(f+1, ub);
			x = f+1;
			push(&lbStack, &x);
			x = ub;
			push(&ubStack, &x);
		}
		if(f-1 > lb)
		{
			int x;
			// push(lb, f-1);
			x = lb;
			push(&lbStack, &x);
			x = f-1;
			push(&ubStack, &x);		
		}
	}
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
