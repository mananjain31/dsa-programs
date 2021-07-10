#include<stdio.h>
#include<stdlib.h>
//stack implementaton starts
typedef struct __stack_node
{
struct __stack_node* next;
int lb;
int ub;
}StackNode;
typedef	struct __stack
{
StackNode *top;
int size;
}Stack;

void initStack(Stack* stack)
{
stack->top = NULL;
stack->size = 0;
}

void pop(Stack* stack, int* lb, int* ub)
{
StackNode* t;
*lb = stack->top->lb; 
*ub = stack->top->ub;
t = stack->top;
stack->top = stack->top->next;
stack->size--;
free(t);
}

void push(Stack* stack, int lb, int ub)
{
StackNode* t = (StackNode*)malloc(sizeof(StackNode));
t->lb = lb;
t->ub = ub;
t->next = stack->top;
stack->top = t;
stack->size++;
}

int isStackEmpty(Stack* stack)
{
return stack->size == 0;
}
//stack implementation ends
void swapIfGreater(int *first, int *last)
{
if(*first > *last)
{
*first = *first + *last;
*last = *first - *last;
*first = *first - *last;
}
}
void stoogeSort(int* a, int lb, int ub)
{
// int len = (ub-lb+1);
// int twoThird = len - (len/3);
// int diff = twoThird-1;
// swapIfGreater(a+lb,a+ub);
// if(len >= 3)
// {
// stoogeSort(a,lb,lb+diff); // left
// stoogeSort(a,ub-diff,ub); //right
// stoogeSort(a,lb,lb+diff); //left
// }
int len, twoThird, diff;
Stack stack;
initStack(&stack);
push(&stack,lb,ub);
while(!isStackEmpty(&stack))
{
pop(&stack,&lb,&ub);
swapIfGreater(a+lb,a+ub);
len = (ub-lb+1);
twoThird = len - (len/3);
diff = twoThird-1;
if(len >= 3)
{
//stoogeSort(a,lb,lb+diff); // left
push(&stack,lb,lb+diff);
// stoogeSort(a,ub-diff,ub); //right
push(&stack,ub-diff,ub);
// stoogeSort(a,lb,lb+diff); //left
push(&stack,lb,lb+diff);
}
}
}
int main()
{
int n,i;
int *a;
printf("Enter Collection size -> ");
scanf("%d", &n);
a = (int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
printf("Enter a Number : ");
scanf("%d", a+i);
}
stoogeSort(a,0,n-1);
for(i=0;i<n;i++)printf("%d\n",*(a+i));
free(a);
return 0;
}