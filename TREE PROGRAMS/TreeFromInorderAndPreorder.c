#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}TreeNode;
				
TreeNode* createTreeFromPreorderAndInorder(int*, int*, int);
void inorder(TreeNode*);
void preorder(TreeNode*);
void postorder(TreeNode*);
int main()
{
	int *in,*pre;
	int size;
	printf("Enter number of nodes : ");
	scanf("%d", &size);
	in = (int*)malloc(sizeof(int) * size);
	pre = (int*)malloc(sizeof(int) * size);
	printf("Enter Preorder Traversal : \n");
	for(int i=0;i<size;i++) scanf("%d", pre+i);
	printf("Enter Inorder Traversal : \n");
	for(int i=0;i<size;i++) scanf("%d", in+i);
	TreeNode* root = createTreeFromPreorderAndInorder(pre, in, size); 
	preorder(root);
	inorder(root);
	postorder(root);	
	return 0;
}

int binarySearch(int* a, int si, int ei, int val)
{
	while(si <= ei)
	{
		int mid = (si+ei)/2;
		if(a[mid] == val)
			return mid;
		else if(a[mid] < val) si = mid+1;
		else ei = mid-1;
	}
	return -1;
}
int idx = 0;
TreeNode* recur(int* pre, int* in, int size, int si, int ei)
{
	if(idx >= size || si > ei) return NULL;
	int fi = binarySearch(in,si,ei,pre[idx]);
	if(fi == -1) return NULL;
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = pre[idx];
	idx++;
	node->left = recur(pre, in, size, si, fi-1);
	node->right = recur(pre, in, size, fi+1, ei);
	return node;
}
TreeNode* createTreeFromPreorderAndInorder(int* pre, int* in, int size)
{
	idx = 0;
	return recur(pre, in, size, 0, size-1);
}



void _inorder(TreeNode* n)
{
	if(n==NULL) return;
	_inorder(n->left);
	printf("%d ", n->data);
	_inorder(n->right);	
}
void inorder(TreeNode* n)
{
	printf("Inorder Traversal\n");
	_inorder(n);	
	printf("\n");
}
void _preorder(TreeNode* n)
{
	if(n==NULL) return;
	printf("%d ", n->data);
	_preorder(n->left);
	_preorder(n->right);	
}
void preorder(TreeNode* n)
{
	printf("Preorder Traversal\n");
	_preorder(n);	
	printf("\n");
}
void _postorder(TreeNode* n)
{
	if(n==NULL) return;
	_postorder(n->left);
	_postorder(n->right);	
	printf("%d ", n->data);
}
void postorder(TreeNode* n)
{
	printf("Postorder Traversal\n");
	_postorder(n);	
	printf("\n");
}