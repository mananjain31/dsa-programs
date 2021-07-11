#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}TreeNode;

struct Node* root = NULL;
struct Node* insert(struct Node*, int data);
void inorder(struct Node*);
void preorder(struct Node*);
void postorder(struct Node*);
void iterativeInorder(struct Node*);
void iterativePreorder(struct Node*);
void iterativePostorder(struct Node*);

				
int main()
{
	int data,ch=1;
	while(ch)
	{
		printf("\n...BINARY SEARCH TREE...\n");
		printf("1. Insert Data\n");
		printf("2. Recursive inorder Traversal\n");
		printf("3. Recursive Preorder Traversal\n");
		printf("4. Recursive Postorder Traversal\n");
		printf("5. Iterative inorder Traversal\n");
		printf("6. Iterative Preorder Traversal\n");
		printf("7. Iterative Postorder Traversal\n");
		printf("0. Exit\n");
		printf("Your Choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: 
				printf("Enter data to insert : ");
				scanf("%d",&data);
				root = insert(root,data);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				iterativeInorder(root);
				break;
			case 6:
				iterativePreorder(root);
				break;
			case 7:
				iterativePostorder(root);
				break;
			case 0:
				ch = 0;
				break;
		}
	}
	return 0;
}

struct Node* insert(struct Node* root, int data)
{
	if(root == 	NULL)
	{
		root = (struct Node*)malloc(sizeof(struct Node));
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data < root->data)
	{
		root->left = insert(root->left,data);
	}
	else if(data >= root->data)
	{
		root->right = insert(root->right,data);
	}
	return root;
}


void inorder(struct Node* root)
{
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void preorder(struct Node* root)
{
	if(root == NULL) return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}


void postorder(struct Node* root)
{
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

//stack implementation starts
typedef struct _stack_node
{
	TreeNode* treeNode;
	struct _stack_node* next;
}StackNode;

typedef struct _stack
{
	StackNode *top;
	int size;
}Stack;

void initStack(Stack* stack)
{
	stack->top = NULL;
	stack->size = 0;
}

void push(Stack* stack, TreeNode* treeNode)
{
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->treeNode = (TreeNode*)malloc(sizeof(TreeNode));
	memcpy(node->treeNode, treeNode, sizeof(TreeNode));
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

TreeNode* pop(Stack* stack)
{
	StackNode* node = stack->top;
	// int data = node->data;
	TreeNode* treeNode = (TreeNode*)malloc(sizeof(TreeNode));
	memcpy(treeNode,node->treeNode,sizeof(TreeNode));
	stack->top = stack->top->next;
	free(node->treeNode);
	free(node);
	stack->size--;
	return treeNode;
}

int isStackEmpty(Stack* stack)
{
	return stack->size == 0;
}

//stack implementation ends

void iterativeInorder(TreeNode* root)
{
	TreeNode* treeNode;
	Stack* stack1 = (Stack*)malloc(sizeof(Stack));
	Stack* stack2 = (Stack*)malloc(sizeof(Stack));
	initStack(stack1);
	initStack(stack2);
	if(root==NULL) return;
	push(stack1,root);
	while(!isStackEmpty(stack1) | !isStackEmpty(stack2))
	{
		if(!isStackEmpty(stack1))
		{
			treeNode = pop(stack1);
			push(stack2, treeNode);
			if(treeNode->left) push(stack1, treeNode->left);
		}
		else
		{
			treeNode = pop(stack2);
			printf("%d ", treeNode->data);
			if(treeNode->right) push(stack1, treeNode->right);
		}
	}
}


void iterativePreorder(TreeNode* root)
{
	TreeNode* treeNode;
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	initStack(stack);
	if(root==NULL) return;
	push(stack,root);
	while(!isStackEmpty(stack))
	{
		treeNode = pop(stack);
		printf("%d ",treeNode->data);
		if(treeNode->right) push(stack,treeNode->right);
		if(treeNode->left) push(stack,treeNode->left);
	}
}

void iterativePostorder(TreeNode* root)
{
	TreeNode* treeNode;
	Stack* stack1 = (Stack*)malloc(sizeof(Stack));
	Stack* stack2 = (Stack*)malloc(sizeof(Stack));
	initStack(stack1);
	initStack(stack2);
	if(root==NULL) return;
	push(stack1,root);
	while(!isStackEmpty(stack1))
	{
		treeNode = pop(stack1);
		push(stack2, treeNode);
		if(treeNode->left) push(stack1, treeNode->left);
		if(treeNode->right) push(stack1, treeNode->right);
	}
	while(!isStackEmpty(stack2)) printf("%d ",pop(stack2)->data);
}