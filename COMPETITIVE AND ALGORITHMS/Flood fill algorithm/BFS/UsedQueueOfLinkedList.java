public class UsedQueueOfLinkedList
{
	public static void showArr(int a[][])
	{
		for(int i[] : a)
		{
			for(int j: i)
				System.out.print(j + " ");
			System.out.println();
		}
		System.out.println();
	}
	public static void main(String[] args) 
	{
		Character[][] a = new Character[14][14];
		for (int i=0; i<a.length; i++)
			for (int j=0; j<a[0].length; j++)
				a[i][j] = ' ';
		FloodFill<Character> f = new FloodFill<Character>();
		f.execute (a, 6, 6, 'X');
	}
}
class FloodFill<T>
{
	public void showArr(T a[][])
	{
		// try{Thread.sleep(150);}catch(Exception e){}
		for(T[] i : a)
		{
			for(T j: i)
				System.out.print(j + " ");
			System.out.println();
		}
		System.out.println();
	}
	public void execute(T a[][], int row, int column, T newColor)
	{
		int ct = 0;
		T oldColor = a[row][column];
		if (oldColor == newColor) return;
		int n = a.length;
		int m = a[0].length;
		Queue<Integer> q = new Queue<>();
		q.enque(row, column);
		while ( !q.empty() )
		{
			Node node = q.deque();
			int r = (int)node.x;
			int c = (int)node.y;
			if (r < 0 || r >= n || c < 0 || c >= m || a[r][c] != oldColor)
				continue;
			else
			{
				a[r][c] = newColor;
				q.enque(r, c+1);
				q.enque(r, c-1);
				q.enque(r+1, c);
				q.enque(r-1, c);
				ct = Math.max(q.count(), ct);
				showArr(a);

			}
		}
		System.out.println(ct);
	}
}
class Queue<T> 
{
	Node<T> front, rear;
	public int count()
	{
		int ct = 0;
		for(Node i = front; i != null; i = i.next)
			ct++;
		return ct;
	}
	public void enque(T data, T data2)
	{
		if (front == null)
		{
			front = new Node<T>(data, data2);
			rear = front;
		}
		else
		{
			rear.next = new Node<T>(data, data2);
			rear = rear.next;
		}
	}
	public Node deque()
	{
		Node<T> t= front;
		if (front == rear)
			rear = null;
		if (front != null)
			front = front.next;
		return t;
	}
	public void show()
	{
		for(Node i = front; i != null; i = i.next)
			System.out.print("["+i.x+","+i.y+"] ");
	}

	public void showln()
	{
		for(Node i = front; i != null; i = i.next)
			System.out.print("["+i.x+","+i.y+"] ");
		System.out.println();
	}
	public boolean empty()
	{
		if (front == null) return true;
		return false;
	}
}
class Node<T>
{
	T x, y;
	Node<T> next;
	Node(T data, T data2)
	{
		x = data;
		y = data2;
	}
}