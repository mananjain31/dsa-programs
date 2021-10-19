#include <stdio.h>
#include <stdlib.h>
typedef struct _BSTNode { 
	struct _BSTNode *left;
	struct _BSTNode *right;
	int data;
}BSTNode;

typedef struct _BST {
	BSTNode* root;
}BST;

void inorderTraversal(BSTNode*);
void preorderTraversal(BSTNode*);
void postorderTraversal(BSTNode*);
BSTNode* createNode(int data);
BSTNode* addNode(BSTNode* node, int data);
int determineIdenticalTrees(BSTNode* node1, BSTNode* node2)
{
	if(node1 == NULL && node2 == NULL) return 1;
	if(node1 == NULL) return 0;
	if(node2 == NULL) return 0;
	if(node1->data != node2->data) return 0;
	int left = determineIdenticalTrees(node1->left, node2->left);
	int right = determineIdenticalTrees(node1->right, node2->right);
	return (left == 1 && right == 1) ? 1 : 0;
}

int main()
{
	BST* bst1 = (BST*)malloc(sizeof(BST));
	BST* bst2 = (BST*)malloc(sizeof(BST));
	BST* bst3 = (BST*)malloc(sizeof(BST));
	bst1->root = bst2->root = bst3->root = NULL;

	bst1->root = addNode(bst1->root,50);
	bst1->root = addNode(bst1->root,100);
	bst1->root = addNode(bst1->root,30);
	bst1->root = addNode(bst1->root,10);

	bst2->root = addNode(bst2->root,50);
	bst2->root = addNode(bst2->root,100);
	bst2->root = addNode(bst2->root,30);
	bst2->root = addNode(bst2->root,10);

	bst3->root = addNode(bst3->root,50);
	bst3->root = addNode(bst3->root,100);
	bst3->root = addNode(bst3->root,10);//was 30
	bst3->root = addNode(bst3->root,30);//was 10

	printf("Printing traversals just for testing puropse\n");
	printf("BST1\n");
	inorderTraversal(bst1->root);
	preorderTraversal(bst1->root);
	postorderTraversal(bst1->root);
	printf("BST2\n");
	inorderTraversal(bst2->root);
	preorderTraversal(bst2->root);
	postorderTraversal(bst2->root);
	printf("BST3\n");
	inorderTraversal(bst3->root);
	preorderTraversal(bst3->root);
	postorderTraversal(bst3->root);

	printf("bst1 and bst2 are same ? %s\n", determineIdenticalTrees(bst1->root, bst2->root)==1 ? "YES" : "NO");
	printf("bst1 and bst3 are same ? %s\n", determineIdenticalTrees(bst1->root, bst3->root)==1 ? "YES" : "NO");
}


BSTNode* createNode(int data)
{
	BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}
BSTNode* addNode(BSTNode* node, int data)
{
	if(!node) return createNode(data);
	if(node->data > data) node->left = addNode(node->left, data);
	else node->right = addNode(node->right, data);
	return node;
}
void _inorderTraversal(BSTNode* node)
{
	if(!node)return;
	_inorderTraversal(node->left);
	printf("%d ", node->data);
	_inorderTraversal(node->right);
}
void _preorderTraversal(BSTNode* node)
{
	if(!node)return;
	printf("%d ", node->data);
	_preorderTraversal(node->left);
	_preorderTraversal(node->right);
}
void _postorderTraversal(BSTNode* node)
{
	if(!node)return;
	_postorderTraversal(node->left);
	_postorderTraversal(node->right);
	printf("%d ", node->data);
}
void inorderTraversal(BSTNode* node) 
{
	_inorderTraversal(node);
	printf("\n");
}
void preorderTraversal(BSTNode* node) 
{
	_preorderTraversal(node);
	printf("\n");
}
void postorderTraversal(BSTNode* node) 
{
	_postorderTraversal(node);
	printf("\n");
}