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
			System.out.println("4 Postorder Iterative traversal");
			System.out.println("5 Delete Node"); // contains bugs
			System.out.println("6 Count Number of leaf Nodes");
			System.out.println("7 Count Number of levels");
			System.out.println("8 Level Order Traversal");
			System.out.println("9 Average of each level");
			System.out.println("10 Minimum Depth");
			System.out.println("11 Lowest Common Ancestor of 2 nodes");
//			System.out.println("11 Minimum Paths With Given Sum");
			System.out.print("Your Choice : ");
			choice = sc.nextInt();
			if(choice == 1){
				System.out.print("Enter Number to insert : ");
				bst.insert(sc.nextInt());
			} else if(choice  == 2){
				bst.inorderIterative();
			} else if(choice == 3) {
				bst.preorderIterative();
			} else if(choice == 4) {
				bst.postorderIterative();
			} else if(choice == 5){
				System.out.print("Enter Number to delete : ");
				bst.delete(sc.nextInt());
			} else if(choice == 6){
				System.out.println("Number of leaf nodes are : " + bst.countLeaves());
			} else if(choice == 7){
				System.out.println("Number of levels : " + bst.countLevels());
			} else if(choice == 8){
				bst.levelOrderTraversal();
			} else if(choice == 9) {
				int[]a = bst.averageOfEachLevel();
				for(int i : a) System.out.print(i + " ");
				System.out.println();
			} else if (choice == 10) {
				System.out.println("Minimum depth of BST is : " + bst.minimumDepth());
			} else if (choice == 11) {
				System.out.print("Enter First Node Data : ");
				int first = sc.nextInt();
				System.out.print("Enter Second Node Data : ");
				int second = sc.nextInt();
				bst.findLCA(first, second);
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

	void findLCA(int first, int second)
	{
		if(root==null) return;
		BSTNode node = root;
		BSTNode parent = null;
		if(first == second)
		{
			while(node!=null)
			{
				if(node.data == first)break;
				parent = node;
				if(first < node.data) node = node.left;
				else node = node.right;
			}
			if(node == null) System.out.println("Nodes are not present in BST");
			else if(parent == null) System.out.println("Nodes are present at the root");
			else System.out.println(parent.data + "is the Lowest common Ancestor");
		}
		else
		{
			while(node!=null)
			{
				if(node.data == first || node.data == second)break;
				parent = node;
				if(first < node.data && second < node.data ) node = node.left;
				else if (first > node.data && second > node.data ) node = node.right;
				else
				{
					parent = node;
					break;
				}
			}
			if(node == null) System.out.println("Nodes are not present in BST");
			else 
			{
				BSTNode node2 = node;
				while(node!=null)
				{
					if(node.data == first)break;
					if(first < node.data) node = node.left;
					else node = node.right;
				}
				if(node == null)
				{
					System.out.println(first + " not present in the BST");	
					return;
				}
				node = node2;
				while(node!=null)
				{
					if(node.data == second)break;
					if(second < node.data) node = node.left;
					else node = node.right;
				}
				if(node == null)
				{
					System.out.println(second + " not present in the BST");	
					return;
				}	
			}
			if(parent == null) System.out.println("Nodes are present at the root");
			else System.out.println(parent.data + " is the Lowest common Ancestor");
		}
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

		BSTNode replacingNodeParent = node;
		BSTNode replacingNode = null;
		if (node.left == null && node.right == null) {
			//when there exist no nodes at left and right of the node to be deleted
			if (parent == null /*that means this is a root node which is to be deleted*/) this.root = null;
			else if (parent.left == node) parent.left = null;
			else parent.right = null;
			return null;
		}
		if (node.left != null) 
		{
			//when there exist a node at left of the node to be deleted
			replacingNode = node.left;
			while (replacingNode.right != null) 
			{
				replacingNodeParent = replacingNode;
				replacingNode = replacingNode.right;
			}
		} 
		else if (node.right != null) 
		{
			//when there exist a node at right of the node to be deleted
			replacingNode = node.right;
			while (replacingNode.left != null)
			{
				replacingNodeParent = replacingNode;
				replacingNode = replacingNode.left;
			}				
		}
		if (replacingNodeParent.right == replacingNode) replacingNodeParent.right = replacingNode.left;
		else replacingNodeParent.left = replacingNode.left;

		if (parent != null)
			if (parent.left == node) parent.left = replacingNode;
			else parent.right = replacingNode;
		else this.root = replacingNode;
		replacingNode.left = node.left;
		replacingNode.right = node.right;

		return replacingNode;
	}


		// if(node.right != null) replacingNode = node.right;
		// else if(node.left != null) replacingNode = node.left;
		// else{
		// 	if(parent!=null)
		// 		if(parent.left == node) parent.left = null;
		// 		else parent.right = null;
		// 	else this.root = null;
		// 	return node;
		// }
		// while(replacingNode.right!=null) 
		// {
		// 	replacingNodeParent = replacingNode;
		// 	replacingNode = replacingNode.right;
		// }

		// // making the parent of replacing node to point at the right node of replacing node 
		// // in place of replacingNode
		// if(replacingNodeParent.right == replacingNode) replacingNodeParent.right = replacingNode.left;	
		// else replacingNodeParent.left = replacingNode.left;

		// // replacing the node to its replacingNode
		// replacingNode.right = node.right;
		// replacingNode.left = node.left;
		// if(parent == null) this.root = replacingNode;
		// else if(parent.left == node) parent.left = replacingNode;
		// else parent.right = replacingNode;
		// return node;

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
	void postorderIterative()
	{

		Stack<BSTNode> stack = new Stack<>();
		BSTNode t = root;
		if(root!=null)
		do{
			while(t!=null)
			{
				if(t.right!=null) stack.push(t.right);
				stack.push(t);
				t = t.left;
			}
			t = stack.pop();
			BSTNode peek = null;
			if(!stack.isEmpty()) peek = stack.peek(); 
			if(t.right == peek)
			{
				stack.pop();
				stack.push(t);
				t = t.right;
			}
			else
			{
				System.out.print(t.data + " ");
				t = null;
			}
		}while(!stack.isEmpty());
		System.out.println();
	}	


	void levelOrderTraversal()	
	{
		class Node
		{
			BSTNode data;
			Node next;
			Node(BSTNode d) {data = d;}
		}
		class Queue
		{
			Node start, end;
			void insertAtEnd(BSTNode data)
			{
				if(start == null) end = start = new Node(data);
				else 
				{
					end.next = new Node(data);
					end = end.next;
				}
			}
			BSTNode removeFromBeggining()
			{
				if(start == null) return null;
				Node t = start;
				start = start.next;
				if(start == null) end = null;
				return t.data;
			}
			boolean isEmpty()
			{
			 return start == null; 
			}
		}
		//traversal
		Queue queue = new Queue();
		BSTNode bsNode = null;
		queue.insertAtEnd(this.root);
		while(!queue.isEmpty()){
			bsNode = queue.removeFromBeggining();
			System.out.print(bsNode.data + " ");
			if(bsNode.left != null) queue.insertAtEnd(bsNode.left);
			if(bsNode.right != null) queue.insertAtEnd(bsNode.right);
		}
		System.out.println();
	}

	int[] averageOfEachLevel()	
	{
		class Node
		{
			BSTNode data;
			int level;
			Node next;
			Node(BSTNode d, int l) {data = d; level = l;}
		}
		class Queue
		{
			Node start, end;
			void insertAtEnd(BSTNode data, int level)
			{
				if(start == null) end = start = new Node(data, level);
				else 
				{
					end.next = new Node(data, level);
					end = end.next;
				}
			}
			Node removeFromBeggining()
			{
				if(start == null) return null;
				Node t = start;
				start = start.next;
				if(start == null) end = null;
				return t;
			}
			boolean isEmpty()
			{
			 return start == null; 
			}
		}
		
		Queue queue = new Queue();
		ArrayList<Integer> arr = new ArrayList<>();
		Node node = null;
		BSTNode bstNode = null;
		queue.insertAtEnd(this.root, 1);
		int sum = 0;
		int currLevel = 1;
		int n = 0;
		while(!queue.isEmpty()){
			node = queue.removeFromBeggining();
			bstNode = node.data;
			int level = node.level;
			
			if(level == currLevel) 
			{
				sum+=bstNode.data;
				n++;
			}
			else 
			{
				arr.add(sum/n);
				sum = bstNode.data;
				currLevel = level;
				n = 1;
			}

			if(bstNode.left != null) queue.insertAtEnd(bstNode.left, level+1);
			if(bstNode.right != null) queue.insertAtEnd(bstNode.right, level+1);
		}
		arr.add(sum/n);
		int a[] = new int[arr.size()];
		for(int i=0;i<arr.size(); i++) a[i] = arr.get(i);
		return a;
	}

	private int minimumDepth(BSTNode node)
	{
		if(node == null) return 0;
		int left = 1 + minimumDepth(node.left);
		int right = 1 + minimumDepth(node.right);
		if(node.left == null && node.right == null) return 1;
		if(node.left == null) return right;
		if(node.right == null) return left;
		return left < right ? left : right;
	}
	int minimumDepth()
	{
		return minimumDepth(root);
	}

/*
	void minimumPathsWithGivenSum(int sum,ArrayList<String> al, String s, int currSum, int pathLength, BSTNode node)
	{
		if()
		if(node.right != null)
		minimumPathsWithGivenSum(sum, al, s+" "+node.right.data, currSum + node.right.data, root.right);	
		else if(node.left != null)
		minimumPathsWithGivenSum(sum, al, "", 0, root.left);
	}
	void minimumPathsWithGivenSum(int sum)
	{
		ArrayList<String> al = new ArrayList<String>();
		if(root!=null)
		minimumPathsWithGivenSum(sum,al, ""+root.data, root.data, 1, root);	
	}
*/
}