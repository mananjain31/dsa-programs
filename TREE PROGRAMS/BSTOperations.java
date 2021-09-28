import java.util.*;
class BSTOperation
{
	public static void main(String[] args) 
	{
		BST bst = new BST();
		int choice = 0;
		Scanner sc = new Scanner(System.in);
		do{
			System.out.println("Binary Search Tree");
			System.out.println("0 Exit");
			System.out.println("1 Insert");
			System.out.println("2 Inorder Iterative traversal");
			System.out.println("3 Preorder Iterative traversal");
			System.out.println("4 Delete Node");
			System.out.println("5 Count Number of leaf Nodes");
			System.out.println("6 Count Number of levels");
			System.out.print("Your Choice : ");
			choice = sc.nextInt();
			if(choice == 1){
				System.out.print("Enter Number to insert : ");
				bst.insert(sc.nextInt());
			} else if(choice  == 2){
				bst.inorderIterative();
			} else if(choice == 3) {
				bst.preorderIterative();
			} else if(choice == 4){
				System.out.print("Enter Number to delete : ");
				bst.delete(sc.nextInt());
			} else if(choice == 5){
				System.out.println("Number of leaf nodes are : " + bst.countLeaves());
			} else if(choice == 6){
				System.out.println("Number of levels : " + bst.countLevels());
			}
		}while(choice != 0);
	}
}
class BSTNode
{
	int data;
	BSTNode left, right;
	BSTNode(int d){data = d;}
}
class BST
{
	BSTNode root;

	//count number of levels
	private int countLevels(int level, BSTNode node)
	{
		if(node == null) return level;
		int left = countLevels(level + 1, node.left);
		int right = countLevels(level + 1, node.right);
		return left > right ? left : right;	
	}
	int countLevels() 
	{
		if(root == null) return 0;
		int left = countLevels(1, root.left);
		int right = countLevels(1, root.right);
		return left > right ? left : right;
	}

	//cunt number of leaf nodes
	int countLeaves()
	{
		int count  = 0;
		Stack<BSTNode> stack = new Stack<>();
		if(root == null) return 0;
		BSTNode node = root;
		stack.push(node);	
		while(!stack.isEmpty())
		{
			node = stack.pop();
			if(node.left == null && node.right == null) count++;
			else {
				if(node.right != null) stack.push(node.right);
				if(node.left != null) stack.push(node.left);
			}
		}	
		return count;
	}

	//deletion Code
	BSTNode delete(int data)
	{
		BSTNode node = root;
		BSTNode parent = null;
		while(node!=null)
		{
			if(node.data == data) break;
			parent = node;
			if(data < node.data) node = node.left;
			else node = node.right;
		}
		if(node == null) return null;

		// replacing node with its inorder successor if the node has right child 
		// or its inorder predecessor if has left child
		BSTNode replacingNodeParent = node;
		BSTNode replacingNode = null;
		if(node.right != null) replacingNode = node.right;
		else if(node.left != null) replacingNode = node.left;
		else{
			if(parent!=null)
				if(parent.left == node) parent.left = null;
				else parent.right = null;
			else this.root = null;
			return node;
		}
		while(replacingNode.right!=null) 
		{
			replacingNodeParent = replacingNode;
			replacingNode = replacingNode.right;
		}

		// making the parent of replacing node to point at the right node of replacing node 
		// in place of replacingNode
		if(replacingNodeParent.right == replacingNode) replacingNodeParent.right = replacingNode.left;
		else replacingNodeParent.left = replacingNode.left;

		// replacing the node to its replacingNode
		replacingNode.right = node.right;
		replacingNode.left = node.left;
		if(parent == null) this.root = replacingNode;
		else if(parent.left == node) parent.left = replacingNode;
		else parent.right = replacingNode;
		return node;
	}

	private BSTNode insert(BSTNode node,int data)
	{
		if(node == null) return new BSTNode(data);
		if(data < node.data) node.left = insert(node.left, data);
		else node.right = insert(node.right, data);
		return node;
	}
	void insert(int data)
	{
		this.root = insert(this.root, data);
	}


	//	BELOW ARE THE TRAVERSAL FUNCTIONS
	void preorderIterative()
	{
		Stack<BSTNode> stack = new Stack<>();
		if(root == null) return;
		BSTNode node = root;
		stack.push(node);	
		while(!stack.isEmpty())
		{
			node = stack.pop();
			System.out.print(node.data + " ");
			if(node.right != null) stack.push(node.right);
			if(node.left != null) stack.push(node.left);
		}
		System.out.println();
	}
	void inorderIterative()
	{
		Stack<BSTNode> stack = new Stack<>();
		if(root == null) return;
		BSTNode node = root;
		while(node!=null)
		{
			stack.push(node);
			node = node.left;
		}
		while(!stack.isEmpty())
		{
			node = stack.pop();
			System.out.print(node.data + " ");
			node = node.right;
			while(node!=null)
			{
				stack.push(node);
				node = node.left;
			}
		}
		System.out.println();
	}	
}