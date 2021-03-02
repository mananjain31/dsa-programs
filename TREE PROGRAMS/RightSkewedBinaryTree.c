#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root = NULL;
struct Node* insert(struct Node*, int data);
void infix(struct Node*);
void prefix(struct Node*);
void postfix(struct Node*);

int main()
{
	int data,ch=1;
	while(ch)
	{
		printf("\n..RIGHT SKEWED BINARY TREE...\n");
		printf("1. Insert Data\n");
		printf("2. Infix Traversal\n");
		printf("3. Prefix Traversal\n");
		printf("4. Postfix Traversal\n");
		printf("5. Exit\n");
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
				infix(root);
				break;
			case 3:
				prefix(root);
				break;
			case 4:
				postfix(root);
				break;
			case 5:
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
	else 
	{
		root->right = insert(root->right,data);
	}
	return root;
}


void infix(struct Node* root)
{
	if(root == NULL) return;
	infix(root->left);
	printf("%d ",root->data);
	infix(root->right);
}

void prefix(struct Node* root)
{
	if(root == NULL) return;
	printf("%d ",root->data);
	prefix(root->left);
	prefix(root->right);
}


void postfix(struct Node* root)
{
	if(root == NULL) return;
	postfix(root->left);
	postfix(root->right);
	printf("%d ",root->data);
}